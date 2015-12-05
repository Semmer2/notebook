Java IO与文件操作
====================
总的来说Java的IO有四个基类：`InputStream`,`OutputStream`,`Reader`,`Writer`.
前两个派生的子类，主要是对字节为单位的数据进行读写。后两个派生的子类主要是对相应字符编码的数据进行读写。 

如果实现`Closeable`接口，需要关闭改流，如果实现`AutoCloseable`接口，在使用try-catch字句是可以自动关闭流。
* InputStream实现了Closeable, AutoCloseable
* OutputStream实现了Closeable, Flushable, AutoCloseable
* Reader实现了Closeable, AutoCloseable, Readable
* Wirter实现了Closeable, Flushable, Appendable, AutoCloseable

Java的文件操作主要通过`File`,`FileInputStream`,`FileOutputStream`,`PrintWriter`来操作。

###　InputStream子类
InputStream类还可以对流进行标记，方便以后重新读取：

	public void mark(int readAheadLimit)
	public void reset() throws IOException
	public boolean markSupported()

一般都实现了如下方法

	int	available()
	void	close()
	void	mark(int readlimit)
	boolean	markSupported()
	abstract int	read()
	int	read(byte[] b)	// 不是都实现了
	int	read(byte[] b, int off, int len)
	void	reset()
	long	skip(long n)

#### DataInputStream
实现的接口：Closeable, AutoCloseable
	DataInputStream(InputStream in)

可以read指定基本类型的数据。如果确定流是UTF可以使用`String readUTF()`和`static String readUTF(DataInput in)`

#### BufferedInputStream
预先读入大量字节，避免多次请求数据。

	BufferedInputStream(InputStream in)
	BufferedInputStream(InputStream in, int size)
	int read()
	int read(byte[] b, int off, int len)

#### FileInputStream

	FileInputStream(File file)
	FileInputStream(FileDescriptor fdObj)
	FileInputStream(String name)
	int	read()
	int	read(byte[] b)
	int	read(byte[] b, int off, int len)

#### PushbackInputSteam

	PushbackInputStream(InputStream in)
	PushbackInputStream(InputStream in, int size)
	int	read()
	int	read(byte[] b, int off, int len)
	void	unread(byte[] b)
	void	unread(byte[] b, int off, int len)
	void	unread(int b)

### OutputStream
子类一般都实现了如下方法。

	void	close()
	void	flush()
	void	write(byte[] b)
	void	write(byte[] b, int off, int len)
	abstract void	write(int b)

#### BufferedOutputStream

	BufferedOutputStream(OutputStream out)
	BufferedOutputStream(OutputStream out, int size) 
	void	flush()
	void	write(byte[] b, int off, int len)
	void	write(int b)

#### DataOutputStream
与`DataInputStream`类似，可以write指定基本类型的数据。如果确定流是UTF可以使用`String writeUTF()`和`static String writeUTF(DataOuput in)`

	DataOutputStream(OutputStream out)
	void flush()
	int	size()

#### FileOutputStream

	FileOutputStream(File file)
	FileOutputStream(File file, boolean append)
	FileOutputStream(FileDescriptor fdObj)
	FileOutputStream(String name)
	FileOutputStream(String name, boolean append)

相关方法

	void	close()
	protected void	finalize()
	FileChannel	getChannel()
	FileDescriptor	getFD()
	void	write(byte[] b)
	void	write(byte[] b, int off, int len)
	void	write(int b)

### Reader

#### BufferedReader
实现了接口：Closeable, AutoCloseable

	BufferedReader(Reader in)
	BufferedReader(Reader in, int sz)
	int	read()
	int	read(char[] cbuf, int off, int len)
	String	readLine()

#### InputStreamReader
实现了接口：Closeable, AutoCloseable

	InputStreamReader(InputStream in)
	InputStreamReader(InputStream in, Charset cs)
	InputStreamReader(InputStream in, CharsetDecoder dec)
	InputStreamReader(InputStream in, String charsetName)

其他方法

	void	close()
	String	getEncoding()
	int	read()
	int	read(char[] cbuf, int offset, int length)
	boolean	ready()

#### PushbackReader

### Writer

#### BufferedWriter
实现了接口：Closeable, Flushable, Appendable, AutoCloseable

	BufferedWriter(Writer out)
	BufferedWriter(Writer out, int sz)
	void	close()
	void	flush()
	void	newLine()
	void	write(char[] cbuf, int off, int len)
	void	write(int c)
	void	write(String s, int off, int len)

#### OutputStreamWriter
实现了接口：Closeable, Flushable, Appendable, AutoCloseable

	OutputStreamWriter(OutputStream out)
	OutputStreamWriter(OutputStream out, Charset cs)
	OutputStreamWriter(OutputStream out, CharsetEncoder enc)
	OutputStreamWriter(OutputStream out, String charsetName)

其他方法

	void	close()
	void	flush()
	String	getEncoding()
	void	write(char[] cbuf, int off, int len)
	void	write(int c)
	void	write(String str, int off, int len)

#### PrintWriter
这个类可以使用print,println,printf,write等多种方法，是输出方法的最佳选择。

	PrintWriter(File file)
	PrintWriter(File file, String csn)
	PrintWriter(OutputStream out)
	PrintWriter(OutputStream out, boolean autoFlush)
	PrintWriter(String fileName)
	PrintWriter(String fileName, String csn)
	PrintWriter(Writer out)
	PrintWriter(Writer out, boolean autoFlush)

### File
### RandomAccessFile
### Scanner
