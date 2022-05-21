<style>
strong {
    color:#00F9A5;
    size: 100px;
    margin: 0em;
    font-size: large;
    font-style: italic;
}
</style>
# c++ 11

## 1. shared_ptr weak_ptr unique_ptr
   - shared_ptr 内存持有引用计数，当复制或拷贝时应用计数加1，当析构时引用计算减1。
   - weak_ptr weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。同时weak_ptr 没有重载*和->，但可以使用 **lock()** 获得一个可用的 shared_ptr 对象（引用计数会增加1）
      - unique_ptr实现的是专属所有权语义，用于独占它所指向的资源对象的场合。某个时刻只能有一个unique_ptr指向一个动态分配的资源对象，也就是这个资源不会被多个unique_ptr对象同时占有，它所管理的资源只能在unique_ptr对象之间进行移动，不能拷贝，所以它只提供了移动语义。
## 2. 右值引用和移动语义
1. std::move()返回的必是右值引用。
2. std::forward()是只有在实参是右值时才返回的右值引用。



## 3. vector list map unordered_map   erase(iterator);、
1. vector list 区别：
    - vector底层是连续结构；list底层是非连续结构
    - vector支持随机访问；list不支持随机访问
    - vector迭代器是原生指针；list迭代器是封装结点的一个类
    - vector在插入和删除时可能会导致迭代器失效；list在删除的时候会导致当前迭代器指向的结点失效
    - vector不容易造成内存碎片，空间利用率高；list容易造成内存碎片，空间利用率低
    - vector在非尾插，删除的时间复杂度为O(n)，list在任何地方插入和删除的时间复杂度都为O(1)
    - 使用场景：  
        vecotr需要高效存储，支持随机访问，不关心插入删除效率；list大量插入和删除操作，不关心随机访问
2. map 底层实现是红黑树。  其特点：     
    - 根节点和叶子节点(叶子节点是nullptr节点)都是黑色。
    - 红色节点的孩子节点都是黑色。
    - 从其任一节点到其每个叶子节点的简单路径上都包含相同个数的黑色节点。
     


  
# c++ 使用手法
## 1. 多态实现

## RAII  
1. RAII是Resource Acquisition Is Initialization的简称，其翻译过来就是“资源获取即初始化”，即在构造函数中申请分配资源，在析构函数中释放资源，它是C++语言中的一种管理资源、避免泄漏的良好方法。
2.    RAII的典型应用  
   在资源管理方面，智能指针(std::shared_ptr和std::unique_ptr)是RAII最具代表性的实现，使用了智能指针，可以实现自动的内存管理，再也不用担心忘记delete造成内存泄漏了。 
   在状态管理方面，线程同步中使用std::unique_lock或std::lock_guard对互斥量std::mutex进行状态管理也是RAII的典型实现，通过这种方式，我们再也不用担心互斥量之间的代码出现异常而造成线程死锁。  
   总结起来说，RAII的核心思想是将资源或状态与类对象的生命周期绑定，通过C++语言机制，实现资源与状态的安全管理。

## 编译调试相关
1. g++ <==============> gcc -lstdc++
2. gdb 调试多线程
3. 
