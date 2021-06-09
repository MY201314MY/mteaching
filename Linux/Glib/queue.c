/*
    reference url:https://blog.csdn.net/andylauren/article/details/79313181
*/

#include <glib.h>
#include <unistd.h>
#include <sys/syscall.h>

GAsyncQueue *async_queue = NULL;

gpointer thread_1(gpointer data)
{
    gint *p;

    while(1)
    {
        g_print("%s %ld enter.\r\n", __func__, syscall(__NR_gettid));
        g_async_queue_lock(async_queue);
        p = (gint*)g_async_queue_pop_unlocked(async_queue);
        g_print("%s pop: %d\r\n", __func__, *p);
        g_print("queue length:%d\r\n", g_async_queue_length_unlocked(async_queue));
        g_async_queue_unlock(async_queue);
        g_print("- - - %s exit - - -.\r\n\r\n", __func__);
    }
}

gpointer thread_2(gpointer data)
{
    gint temp = 0;

    while(1)
    {
        //g_print("thread %s %ld enter.\r\n", __func__, syscall(__NR_gettid));
        g_async_queue_lock(async_queue);
        temp++;
        g_async_queue_push_unlocked(async_queue, &temp);
        g_print("%s push: %d\r\n", __func__, temp);
        g_async_queue_unlock(async_queue);
        g_usleep(10*1000*1000);
    }
}

int main()
{
    GThread *gthread1, *gthread2;
    async_queue = g_async_queue_new();
    gthread1 = g_thread_new("th 1", thread_1, NULL);
    gthread2 = g_thread_new("th 2", thread_2, NULL);

    g_thread_join(gthread1);
    g_thread_join(gthread2);

    g_print("---End---\r\n");

    return 0;
}
