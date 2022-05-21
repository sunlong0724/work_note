<style>
strong {
    color:#00F9A5;
    size: 100px;
    margin: 0em;
    font-size: large;
    font-style: italic;
}
</style>

# 一、LINUX 系统相关
https://blog.csdn.net/mou_it/category_8507188.html

# 二、 epoll select 区别
    https://blog.csdn.net/gymaisyl/article/details/83962671
    https://cloud.tencent.com/developer/article/1005481
    https://blog.csdn.net/dog250/article/details/50528373
   
1. select 缺点：  
    （1）被监控的fds集合限制为1024，1024太小了，我们希望能够有个比较大的可监控fds集合  
    （2）fds集合需要从用户空间拷贝到内核空间的问题，我们希望不需要拷贝  
    （3）当被监控的fds中某些有数据可读的时候，我们希望通知更加精细一点，就是我们希望能够从通知中得到有可读事件的fds列表，而不是需要遍历整个fds来收集。
2. epoll 优点  
     (1) 支持的FD上限是最大可以打开文件的数目(在1GB内存的机器上大约是10万左右，具体数目可以cat /proc/sys/fs/file-max查看,一般来说这个数目和
        系统内存关系很大)
    （2）fds集合拷贝问题的解决
        对于IO多路复用，有两件事是必须要做的(对于监控可读事件而言)：1. 准备好需要监控的fds集合；2. 探测并返回fds集合中哪些fd可读了。细看select或poll的函数原型，我们会发现，每次调用select或poll都在重复地准备(集中处理)整个需要监控的fds集合。然而对于频繁调用的select或poll而言，fds集合的变化频率要低得多，我们没必要每次都重新准备(集中处理)整个fds集合。于是，epoll引入了epoll_ctl系统调用，将**高频调用的epoll_wait和低频的epoll_ctl隔离开**。
    （3) fds集合按需遍历

    epoll_create
    epoll_ctrl 
    epoll_wait
   
# 三、resuse_port resuse_addr
