概述
======

## block element
#### 标题有两种方式
* \=\=\=\=\=\=\=\=表示一阶标题
* \-\-\-\-\-\-\-\-表示二阶标题
* “#”个数由1~6对应1至6级标题
* \# 一级标题
* \#\#二级标题
* \#\#\#三级标题
* \#\#\#\#四级标题\#\#   //后面也可以加上任意数量的#号
* \#\#\#\#\#五级标题
* \#\#\#\#\#\#六级标题

#### 引用

> “>”表示标题的应用

> 这是一个引用:>

> 也可以在一个段落前面进行引用而不用每一行都进行引用

> 你也可以在一段引用中使用其他markdown语法

> 例如无序列表：> *

> 斜体：> *斜体*

> 引用的引用：> >

#### 列表
* “*”表示无序列表
+ 或者“+”
- 或者“-”
* 数字&英文点号. 

1. 这是有序列表
2. 数字
3. 加点号
2. 无序的数字
2. 也会变成有序的
1. 不用在意数字

* 为了让段落看起来漂亮
  可以统一进行缩进
* inorder to invoid the number followed by a point,just like 
* 1983. something, you can type a \,just like
* 1983\. something

#### 程序块
```c
  the begin with 4 spaaces or a tabcan be take as a paragraph  
  just like this  
  untill the tab or 4 sapces is vanished  
  this is a demo  
  finished
```

#### Devide line

* star symbol or minus symmbol can use as devide line,just like this

"*****"
*******

"* * *"
* * * *

"- - -"
- - - -

"-----"
 -------

## paragraph element
#### link
###### 行内式
* use the ( to close the link,just like(http://www.baidu.com)
* or like this [百度](http://www.baidu.com "Baidu")
* 如果访问主机资源，可以使用相对路径[About](/about/)

###### 参考式
* 这是一个参考是示例[例子][id]
[id]:http://www.baidu.com
* id的标识可以再文件的任意位置
* 如果id为空，则标识符为名字，例如[例子][]
[例子]:http://www.baidu.com
* 链接内容的形式为：
* 首先是[]里面包含了标识符或者名字
* 紧跟: 然后是链接的地址
* 最后是可选名"optional tittle here"
* 可选名可以用引号“”、单引号‘’、小括号（）
* 注意id中的名字是不区分大小写的，即[A]和[a]是一样的

#### 强调
* 强调包括斜体和加粗，可用符号是*或_
* 斜体是单符号包围*斜体*
* 加粗是双符号包围**加粗**
* 如果*或_两遍都有空格则被当成普通符号处理
* 想直接输入*或_可以输入反斜线\* \_

#### 代码
* 位于文字中的一小段代码，可以用\`\`来包围
* 例如`printf("helloworld")`

#### 图片
* 图片的插入形式和链接很像，也分为内行式和参考式

###### 内行式：
* ![Alt text](/path/to/img.jpg)
* 格式：
* 首先一个感叹号!
* 跟着一个[]，里面是代替图片的文字
* 接着是()，里面是图片的地址

###### 参考式
* ![Alt text][id]
[id]:url/to/image "optional tittle"

## 其他
#### 自动链接
* 当使用到链接或者电子邮箱时，可以使用\<\>将其括起来
* 如：<semmer2@163.com>
* <http://www.baidu.com>

#### 反斜杠
* 可以使用反斜杠\来输入有特殊意义的符号，
* 例如:
* \\ \` \* \_ \{\} \[\] \(\) \# \+ \- \. \!

#### 表格

| 编号 | 说明 | 国外|
| --- | --- | --- |
| 1 | 上海 | 纽约 |
| 2 | 南京 | 伦敦 |
| 3 | 北京 | 旧金山 |

* 注意表格表头后面需要一个划分线


#### 写在后面：至此所有语法书写完毕。

