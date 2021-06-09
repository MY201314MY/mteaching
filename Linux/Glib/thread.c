#include <glib.h>
#include <unistd.h>
#include <sys/syscall.h>

gpointer thread_1(gpointer data)
{
    static gint var = 128;

    g_print("thread %s %ld enter.\r\n", __func__, syscall(__NR_gettid));
    g_print("thread %ld data:%s\r\n", syscall(__NR_gettid), ((char*)data));
    g_usleep(2*1000*1000);
    g_print("thread %s %ld exit!\r\n", __func__, syscall(__NR_gettid));

    g_thread_exit((gpointer)&var);

}

int main()
{
    g_print("- - - Glib Example - - -\r\n");

    gpointer message = "thread";

    GThread *gthread = NULL;
    gthread = g_thread_new("function 1", thread_1, message);
    g_print("G thread join: %d\r\n", *((gint *)g_thread_join(gthread)));

    g_print("\r\nT_T_T\r\n");
    g_usleep(5*1000*1000);

    g_print("\r\n---End---\r\n");


    return 0;
}