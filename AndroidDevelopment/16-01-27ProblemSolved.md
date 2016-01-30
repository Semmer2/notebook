第一个android程序遇到的问题及解决办法
==========
### 1.问题

在按照书上所说方法创建第一个android程序（minimum required sdk为2.2，target sdk为5.1.1，Complie with为5.1.1）以后出现错误：R cannot be resolved to a vriable

### 2.分析

```
根据console窗口显示，错误信息出在appcompat_v7 -> res -> values-v23 -> styles_base.xml 中，具体信息为<style name="Base.Widget.AppCompat.Button.Colored" parent="android:Widget.Material.Button.Colored" />
[2016-01-27 17:49:37 - appcompat_v7] E:\AndroidDevelopment\eclipse\WorkSpace\appcompat_v7\res\values-v23\styles_base.xml:20: error: Error retrieving parent for item: No resource found that matches the given name 'android:Widget.Material.Button.Colored'.
[2016-01-27 17:49:37 - appcompat_v7] 
[2016-01-27 17:49:37 - appcompat_v7] E:\AndroidDevelopment\eclipse\WorkSpace\appcompat_v7\res\values-v23\styles_base_text.xml:19: ##error: Error retrieving parent for item: No resource found that matches the given name 'android:TextAppearance.Material.Widget.Button.Inverse'.##
[2016-01-27 17:49:37 - appcompat_v7]
```

### 3.解决

百度相关信息发现一下网站[http://www.phperz.com/article/14/1204/39233.html]，按照他提供的方法，可知问题是因为所需的依赖包没能正确安装。根据第一个解决办法可知，需要安装SDK Platform & Android Support Repository & Android Support Library & Google Play service & Google Repository这些东西，因为暂时没有wifi所以选择第二种方法。
即在创建新android工程时，将minimum required SDK 设置为4.1及以上即可，也就是不使用appcompat_v7，据此，我猜测这个文件夹是为了兼容性所创建的。

### 至此，所有问题解决

