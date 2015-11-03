C文件操作
=================
[C语言文件操作](http://www.cnblogs.com/likebeta/archive/2012/06/16/2551780.html)

#### 打开文件
FILE *fopen(char *pname,char *mode);

1. mode: r,w,a,t,b,+
2. 返回值：正常返回文件指针，错误返回`NULL`


#### 关闭文件
int fclose(FILE *fp);

1. 返回值：正常返回０，错误返回EOF.

#### 文件的读写
int fgetc(FILE *fp); // 正常返回读取的字符，错误返回EOF

int fputc(int ch,FILE *fp); // 正常返回写入的字符，错误返回EOF

char *fgets(char *str,int n,FILE *fp) // 从fp中获取n-1个字符存入str.正确返回str值，错误返回NULL.应用
feof()或ferror()函数来判别是读取到了文件尾，还是发生了错误

int fputs(char *str,FILE *fp); // 正常返回： 写入文件的字符个数，即字符串的长度。非正常返回：返回一个NULL值，此时应当用feof()或ferror()函数来判别是读取到了文件尾，还是发生了错误。

int fprintf(FILE *fp,char *format,arg_list); // 类似于printf()函数

int fread(void *buffer,unsigned sife,unsigned count,FILE *fp); 
// 从由fp指定的文件中，按二进制形式将sife个数据读count次存入由buffer指出的数据区中。
// 正常返回：实际读取数据块的个数，即count。
// 异常返回：如果文件中剩下的数据块个数少于参数中count指出的个数，或者发生了错误，返回0值。此时可以
// 用feof()和ferror()来判定到底出现了什么情况。

int fwrite(void *buffer,unsigned sife,unsigned count,FILE *fp); // 与fread类似

#### 文件是否结束
int feof(FILE *fp)； // 0假，１真　

#### 文件是否出错
int ferror(FILE *fp);

#### 清除错误标志
void clearerr(FILE *fp);

#### 获文件指针当前位置
long ftell(FILE *fp);

#### 文件指针回到文首
void rewind(FILE *fp);

#### 随机定位文件指针
int fseek(FILE *fp,long offset,int base); 
// 使文件指针fp移到基于base的相对位置offset处。
// base取值
// SEEK_SET： 文件开头
// SEEK_CUR： 当前位置
// SEEK_END： 文件结尾

#### 判断文件是否结束
int feof(FILE *fp);
