
hiredis是redis官方推荐的基于C接口的客户端组件，它提供接口，供c语言调用以操作数据库。我们需要将hiredis安装到我们的系统中，在redis的源码包的deps/hiredis下就有它的源码,也可以另行下载hiredis
安装方法，进入deps/hiredis目录，执行命令：

make
make install
ldconfig   #使动态库在系统中更新生效 mac下不行

