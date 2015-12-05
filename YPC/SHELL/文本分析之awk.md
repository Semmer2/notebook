SHELL文本分析之awk
==================
主要参考如下
[awk学习总结](http://www.cnblogs.com/chengmo/tag/awk/)

--------------------
补充：
### awk使用外部shell变量
#### -v参数
使用`awk -v varname="$outvar" 'print varname;'  filename`

#### 引号操作
在正则表达式中是先双再单，而在执行命令里是先单再双。

    aaa="abc"
    awk '/'"$aaa"'/{print "'$aaa'"}' ttt.txt
