#include <glib.h>

GMainLoop *loop;

gboolean callback(gpointer p)
{
    g_print(".");
    gint temp = (*((gint *)p))--;
    if(!temp){
        g_print("\r\nQuit loop, close the timer.\r\n");
        g_main_loop_quit(loop);
        
        return FALSE;
    }

    return TRUE;
}

int main()
{
    gint i = 10;

    g_print("G main loop.\r\n");
    loop = g_main_loop_new(NULL, FALSE);

    /* GLib Timer Callback */
    g_timeout_add(100, callback, (gpointer)&i);

    g_print("G main loop running...\r\n");
    g_main_loop_run(loop);

    /* the main thread is suspended */
    g_print("G main loop unref\r\n");
    g_main_loop_unref(loop);

    return EXIT_SUCCESS;
}