SQL语句优化
==============
SQL语句优化是MySQL最重要也是最有效的优化方式。

## 慢查日志
慢查日志记录了查询时间长的SQL语句的相关信息。对查询时间长的SQL进行下一步优化。

### 慢查日志的开启

	show variables like 'slow_query_log';	// 如果为OFF设置该变量为ON
	set global slow_query_log = '/home/mysql/sql_log/mysql-slow.log';	// 设置慢查日志存储位置
	set global log_queries_not_using_indexes = on;	// 把没有使用索引的SQL查询的相关信息写入日志
	set global long_query_time = 1;	// 把查询时间大于1的SQL写入日志

### 慢查日志分析工具
#### mysqldumpslow
mysql自带的分析工具，在shell终端直接运行。  

	mysqldumpslow -t 10 /home/mysql-slow.log | more
	// 包含信息有具体查询语句，查询次数，查询时间，加锁时间，使用者等

#### pt-query-digest
输出到文件：`pt-query-digest slow-log > slow_log.report`  
输出到数据库表：`pt-query-digest -review h=127.0.0.1,D=test,p=root,P=3306,u=root,t=query_review --create-reviewtable --review-history t=hostname_slow`  

### 哪些SQL语句需要优化
1. 查询次数多且每次查询所占时间长：pt-query-digest前几项；
2. IO大的SQL：pt-query-digest分析中的`Rows examine`项,扫描行数多IO消耗大；
3. 索引命中率低的SQL：pt-query-digest分析中`Rows examine`远大于`Rows Send`；

## 分析SQL
使用`explain`命令在MySQL客户端对SQL语句分析，是该SQL的执行计划。使用方法：explain+SQL语句。

explain返回各列的含义：
* table：显示这一行的数据属于哪张表；
* type：重要。显示连接使用了哪种类型。最好到最差分别为const,eq_reg（范围查找）,ref（连接关联查找）,range（基于索引的范围查找）,index（索引扫描查找）,all（表扫描）;
* possible_keys:显示可能用到的索引，如果为空，没有可用的索引；
* key：实际使用的索引；
* key_len：索引的长度。越短越好；
* ref：显示索引的哪一列被使用。
* rows：MySQL认为对请求数据必须扫描的行数。
* extra：using filesort(看到这个就需要优化了，因为他需要大量排序)，using temporary(看到这个也需要优化，使用了临时表，一般是发生在对不同列集进行order by，而不是group by);

## 优化count()和max()函数
**count(*)包含所有行，count(column_name)不包含NULL值的行** 
案例：同时找出2014和2015年电影的数量。
办法：select count(release_year='2014' or null) as '2014数量',count(release_year='2015' or null) as '2015数量' from film;
思考：如果不加`or null`那么判断语句返回`false`也会被count计数，只有null，count才不会计数。

案例：对一个简单数据量很大的表进行`explain select max(pay) from payment`得出rows可能很大，他会逐行扫描。  
办法：在`pay`列建立索引`create index idx_pay on payment(pay)`,再次执行explain发现`extra:select tables optimized away`。这时直接从索引取值，没有进行表扫描。

## 子查询优化
通常需要将子查询优化为join查询。注意：join连接时如果有多个相同值会直接匹配连接，这样就会有多个相同的行。可以使用`DISTINCT`去重，如果不能满足需求，还是用子查询。

## GROUP BY优化
原始

	SELECT actor.name COUNT(*) 
	FROM film_actor INNER JOIN actor USING(id)
	GROUP BY film_actor.id;

优化为

	SELECT actor.name c.cnt 
	FROM actor 
	INNER JOIN (SELECT id,COUNT(*) AS cnt FROM film_actor GROUP BY id) AS c 
	USING(id);

过滤条件最好放到子查询内部而不是外部。

## LIMIT优化
LIMIT常用于分页处理，时常会伴随`ORDER BY`从句使用，因此大多时候会造成filesort导致大量IO。例如：

	SELECT id, description FROM film ORDER BY title LIMIT 50,5;

优化方法一：
使用有索引的列或主键进行`ORDER BY`.（索引本身就是按顺序排列的）

优化方法二：
记录上次返回的主键，在下次查询时使用主键过滤。是为了解决从200000行开始取5行而带来的大量遍历。

	SELECT id, description FROM film WHERE id>200000 AND id<=200005 ORDER BY id LIMIT 1,5;

但是！！！要求建立了索引的`id`列顺序且连续增长。
