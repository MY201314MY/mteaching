#include <glib.h>

GMainLoop *loop;

gboolean callback(GIOChannel *channel)
{
    gchar *string;
    gsize len;

    g_io_channel_read_line(channel, &string, &len, NULL, NULL);
    g_print("length:%ld\r\n", len);

    g_print("recv:%s", string); 

    if(!strncmp(string, "quit", 4)){
        g_print("\r\n----EXIT---\r\n");
        g_free(string);
        g_main_loop_quit(loop);
    }
}

int main()
{
    GMainContext *context;
    context = g_main_context_new();

    /* source --> context */
    GIOChannel *channel;
    GSource *source;

    channel = g_io_channel_unix_new(1);
    source = g_io_create_watch(channel, G_IO_IN);
    g_io_channel_unref(channel);

    g_source_set_callback(source, (GSourceFunc)callback, channel, NULL);
    g_source_attach(source, context);
    g_source_unref(source);

    g_print("G main loop.\r\n");
    loop = g_main_loop_new(context, FALSE);

    g_print("G main loop running...\r\n");
    g_print("Input 'quit' to exit.\r\n");
    g_main_loop_run(loop);

    /* the main thread is suspended */
    g_print("G main loop unref\r\n");
    g_main_loop_unref(loop);
    g_main_context_unref(context);

    return EXIT_SUCCESS;
}