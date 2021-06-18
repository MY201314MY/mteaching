#include <glib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define RUN 6

GMutex *mutex = NULL;
GString *s;

gpointer thread_1(gpointer data)
{
    gint i;

    for(i=0;i<RUN;i++)
    {
        if(g_mutex_trylock(mutex) == FALSE)
        {
            g_print("%02d: thread 2 locked the mutex\r\n", i);
        }
        else{
            g_print("thread 1 do something.\r\n");
            g_usleep(1000*1000);
            g_mutex_unlock(mutex);
        }
        g_usleep(1000*1000);
    }
}

gpointer thread_2(gpointer data)
{
    gint i;

    for(i=0;i<RUN;i++)
    {
        if(g_mutex_trylock(mutex) == FALSE)
        {
            g_print("%02d: thread 1 locked the mutex\r\n", i);
        }
        else{
            g_print("thread 2 do something.\r\n");
            g_mutex_unlock(mutex);
        }
    }
}

int main()
{
    g_print("- - - Glib Example - - -\r\n");

    s = g_string_new("Hello");
    g_print("s:%s -- len:%d\r\n", s->str, s->len);
    s = g_string_new("Hello, world");
    g_print("s:%s -- len:%d\r\n", s->str, s->len);

    mutex = g_mutex_new();

    GThread *th1 = g_thread_new("th1", thread_1, NULL);
    GThread *th2 = g_thread_new("th2", thread_2, NULL);

    g_thread_join(th1);
    g_thread_join(th2);

    g_print("- - - - EXIT - - - -\r\n");
    g_mutex_free(mutex);
    g_print("release the mutex.\r\n");

    g_print("\r\n---End---\r\n");

    return 0;
}