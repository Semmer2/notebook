概述
======

## block element
#### 标题有两种方式
* “========”表示一阶标题
* “--------”表示二阶标题
* “#”个数由1~6对应1至6级标题
* #一级标题 #
* ##二级标题 ##
* ###三级标题 ###
* ####四级标题//后面也可以加上一定数量的#号
* #####五级标题
* ######六级标题

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

  the begin with 4 spaaces or a tabcan be take as a paragraph
  just like this
  untill the tab or 4 sapces is vanished
  this is a demo
finished

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
