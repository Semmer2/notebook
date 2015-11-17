单例模式
==========
应用场合：有些对象只需要一个就足够了，如古代皇帝、老婆  
作用：保证整个应用程序中某个实例有且只有一个
类型：饿汉模式、懒汉模式

下面以Java为示例说明。

## 饿汉模式
创建静态实例，在类加载时就创建对象。

1. 构造方法私有化；
2. 创建静态私有对象；
3. 提供获取实例的静态公有方法；

	public class Singleton {
		//1.将构造方法私有化，不允许外部直接创建对象
		private Singleton(){		
		}
		//2.创建类的唯一实例，使用private static修饰
		private static Singleton instance=new Singleton();
		
		//3.提供一个用于获取实例的方法，使用public static修饰
		public static Singleton getInstance(){
			return instance;
		}
	}

## 懒汉模式
声明静态实例，在第一次使用时才创建对象。

1. 构造方法私有化；
2. 声明静态私有对象；
3. 提供获取实例的静态公有方法；

	public class Singleton2 {
		//1.将构造方式私有化，不允许外边直接创建对象
		private Singleton2(){
		}
		//2.声明类的唯一实例，使用private static修饰
		private static Singleton2 instance;
		
		//3.提供一个用于获取实例的方法，使用public static修饰
		public static Singleton2 getInstance(){
			if(instance==null){
				instance=new Singleton2();
			}
			return instance;
		}
	}

## 饿汉模式和懒汉模式区别
1. 加载类或获取对象的快慢；
2. 懒汉线程不安全。如果是多线程，懒汉模式可能由于`if`语句导致创建了多个对象。

## 拓展

### 懒汉线程安全的写法

	public class Singleton {
	    private static Singleton instance;
	    private Singleton (){}
	    public static synchronized Singleton getInstance() {
		if (instance == null) {
		    instance = new Singleton();
		}
		return instance;
	    }
	}

### 静态内部类保证线程安全且不在类初始化时就被加载

	public class Singleton {
	    private static class SingletonHolder {
		private static final Singleton INSTANCE = new Singleton();
	    }
	    private Singleton (){}
	    public static final Singleton getInstance() {
		return SingletonHolder.INSTANCE;
	    }
	}

### 使用枚举
这种方式是Effective Java作者Josh Bloch 提倡的方式，它不仅能避免多线程同步问题，而且还能防止反序列化重新创建新的对象。

	public enum Singleton {
	    INSTANCE;
	    public void whateverMethod() {
	    }
	}

### 双重校验锁

	public class Singleton {
	    private volatile static Singleton singleton;
	    private Singleton (){}
	    public static Singleton getSingleton() {
		if (singleton == null) {
		    synchronized (Singleton.class) {
			if (singleton == null) {
			    singleton = new Singleton();
			}
		    }
		}
		return singleton;
	    }
	}
