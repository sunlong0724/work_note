<style>
strong {
    color:#00F9A5;
    size: 100px;
    margin: 0em;
    font-size: xx-large;
    font-style: italic;
}
</style>
1. vsyscall、系统调用、中断区别
2. 孤儿进程、僵尸进程（https://www.cnblogs.com/anker/p/3271773.html、 https://blog.csdn.net/lxj362343/article/details/108526135）
   - 孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作。
   - 僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。
   - **僵尸进程就是子进程退出时候没有被父进程或init进程收集进程状态，其进程描述符仍然保存在系统中。**
   
3. c++程序内存分布
4. 虚拟地址 物理地址
5. gcc g++编译区别
6. extern "C" {} 作用
7. 移动语义和右值引用
8. tcmalloc jemalloc ptmalloc