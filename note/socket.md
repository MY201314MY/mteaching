### Socket 

**This is for socket refreenced operation.** 

> 在Linux系统中，内核利用文件描述符（File Descriptor）即文件句柄来访问文件，文件描述符是非负整数。
>
> 所谓阻塞方式 **block**，顾名思义，就是进程或是线程执行到这些函数时必须等待某个事件的发生，如果事件没有发生，进程或线程就被阻塞，函数不能立即返回。
>
> 所谓非阻塞方式 **non- block**，就是进程或线程执行此函数时不必非要等待事件的发生，一旦执行肯定返回，以返回值的不同来反映函数的执行情况，如果事件发生则与阻塞方式相同，若事件没有发生则返回一个代码来告知事件未发生，而进程或线程继续执行，所以效率较高

#### Function

##### select

select本质上是通过设置或者检查存放fd标志位的数据结构来进行下一步处理。这样所带来的缺点是：

- 单个进程可监视的fd数量被限制，即能监听端口的大小有限。一般来说这个数目和系统内存关系很大，具体数目可以cat/proc/sys/fs/file-max察看。32位机默认是1024个，64位机默认是2048。

- 对socket进行扫描时是线性扫描，即采用轮询的方法，效率较低：当套接字比较多的时候，每次select()都要通过遍历FD_SETSIZE个Socket来完成调度,不管哪个Socket是活跃的,都遍历一遍。这会浪费很多CPU时间。如果能给套接字注册某个回调函数，当他们活跃时，自动完成相关操作，那就避免了轮询，这正是**epoll**与**kqueue**做的。

- 需要维护一个用来存放大量fd的数据结构，这样会使得用户空间和内核空间在传递该结构时复制开销大。

```c
int select(int maxfdp, fd_set *readset, fd_set *writeset, fd_set *exceptset,struct timeval *timeout);
/*
maxfdp：被监听的文件描述符的总数，它比所有文件描述符集合中的文件描述符的最大值大1，因为文件描述符是从0开始计数的；
readfds、writefds、exceptset分别指向可读、可写和异常等事件对应的描述符集合。
timeout:用于设置select函数的超时时间，即告诉内核select等待多长时间之后就放弃等待
timeout == NULL 表示等待无限长的时
*/
```

###### FD_SET

```c
#include <stdio.h>
#include <sys/types.h>

int main() {
    int isset = 0;

    printf("FD Explore\n");
		/* It's a array. Each member means the status of a detailed File Descriptor. */
    fd_set fdset;
    FD_ZERO(&fdset);

    FD_SET(1, &fdset);
    FD_SET(2, &fdset);
		/* isset = 2 */
    isset = FD_ISSET(1, &fdset);
  	/* isset = 6 */
    isset = FD_ISSET(2, &fdset);


    FD_SET(0, (__int32_t *)&fdset.fds_bits[3]);
    FD_SET(1, (__int32_t *)&fdset.fds_bits[3]);

    return 0;
}
```

##### poll

```c
extern int poll(struct pollfd *, nfds_t, int) __DARWIN_ALIAS_C(poll);
/*
（1）fds：指向一个结构体数组的第0个元素的指针，每个数组元素都是一个struct pollfd结构，用于指定测试某个给定的fd的条件
（2）nfds：表示fds结构体数组的长度
（3）timeout：表示poll函数的超时时间，单位是毫秒
*/
```



- 每个结构体的 events 域是由用户来设置，告诉内核我们关注的是什么，而 revents 域是返回时内核设置的，以说明对该描述符发生了什么事件。

poll的优点
（1）poll() 不要求开发者计算最大文件描述符加一的大小。
（2）poll() 在应付大数目的文件描述符的时候速度更快，相比于select。
（3）它没有最大连接数的限制，原因是它是基于链表来存储的。
**平台兼容性好**

poll的缺点
（1）大量的fd的数组被整体复制于用户态和内核地址空间之间，而不管这样的复制是不是有意义。
（2）与select一样，poll返回后，需要轮询pollfd来获取就绪的描述符，这样会使性能下降
（3）同时连接的大量客户端在一时刻可能只有很少的就绪状态，因此随着监视的描述符数量的增长，其效率也会线性下降

##### epoll

在2.5.44内核中被引进的，几乎具备了之前所说的select、poll的一切优点，被公认为是linux2.6下性能最好的多路I/O就绪通知方法。

epoll优点总结

- 文件描述符数目无上限: 通过epoll_ctl()来注册一个文件描述符, 内核中使用红⿊黑树的数据结构来管理所有需要监控的文件描述符.

- 文件描述符数目无上限: 通过epoll_ctl()来注册一个文件描述符, 内核中使用红⿊黑树的数据结构来管 理所有需要监控的文件描述符.

- 基于事件的就绪通知方式: 一旦被监听的某个文件描述符就绪, 内核会采用类似于callback的回调机制, 迅速激活这个文件描述符. 这样随着文件描述符数量的增加, 也不会影响判定就绪的性能;
-  维护就绪队列: 当文件描述符就绪, 就会被放到内核中的一个就绪队列中. 这样调用epoll_wait获取 就绪文件描述符的时候, 只要取队列中的元素即可, 操作的时间复杂度是O(1);



[Reference URL]: https://blog.csdn.net/weixin_41010318/article/details/80257177
[Reference URL]: https://blog.csdn.net/qq_37964547/article/details/80699489?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164336970716780261945897%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&amp;request_id=164336970716780261945897&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-80699489.nonecase&amp;utm_term=epoll&amp;spm=1018.2226.3001.4450
[Reference URL]: https://blog.csdn.net/u012252959/article/details/48574711





