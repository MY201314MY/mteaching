#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#include "gdbus.h"

#define COM_GDBUS_BUS  G_BUS_TYPE_SESSION
#define COM_GDBUS_NAME "com.gdbus.communication"
#define COM_GDBUS_PATH "/com/gdbus/communication"

static GMainLoop *loop = NULL;
static ComGdbusCommunication *pSkeleton = NULL;

static gboolean setName(ComGdbusCommunication *object, GDBusMethodInvocation *invocation, const gchar *arg, gpointer user_data)
{
    g_print("server set name is called\r\nname:%s\r\n", arg);
    arg = "set name successfully.\r\n";
    com_gdbus_communication_complete_set_name(object, invocation, arg);

    return TRUE;
}

static void name_acquired_handler(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
    g_print("GDBusNameAcquired Callback, bus name:%s\r\n", COM_GDBUS_NAME);
}

static void name_lost_handler(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
    if(connection == NULL)
    {
        g_print("GDBusNameLost Callback, failed to connect D-Bus.\r\n");
    }
    else
    {
        g_print("GDBusNameLost Callback, failed to get D-Bus name.\r\n");
    }
    g_main_loop_quit(loop);
}

static void bus_acquired_handler(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
    GError *perror = NULL;
    pSkeleton = com_gdbus_communication_skeleton_new();
    g_signal_connect(pSkeleton, "handle-set-name", G_CALLBACK(setName), NULL);
    g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(pSkeleton),
                                     connection,
                                     COM_GDBUS_PATH,
                                     &perror);

    if(perror == 0)
    {
        g_print("skeleton export successfully\r\n");
    }else{
        g_print("skeleton export failed:%s\r\n", perror->message);
        g_error_free(perror);
        g_main_loop_quit(loop);
    }
}

void timestr(char *buffer, uint8_t *len)
{
    time_t timestamp;
    struct tm *p;

    time(&timestamp);
    p = gmtime(&timestamp);

    *len = sprintf(buffer, "%02d:%02d:%02d", p->tm_hour, p->tm_min, p->tm_sec);
}

static gboolean sendSignal(gconstpointer p)
{
    char buffer[64];
    uint8_t len;

    timestr(buffer, &len);

    g_print("%s:sever send signal is called!\r\n", buffer);
    gint sig = 1;
    com_gdbus_communication_emit_send_signal(pSkeleton, sig);

    return TRUE;
}

int initGDBusCommunicationForServer()
{
    guint own = g_bus_own_name(
            COM_GDBUS_BUS,
            COM_GDBUS_NAME,
            G_BUS_NAME_OWNER_FLAGS_NONE,
            bus_acquired_handler,
            name_acquired_handler,
            name_lost_handler,
            NULL,
            NULL
    );

    g_timeout_add(10*1000, (GSourceFunc)sendSignal, NULL);

    return 0;
}

static void *input(void* arg)
{
    char string[128] = {0};

    while(true){
        scanf("%s", string);
        printf(".\r\n");
        if(!strcmp("quit", string)){
            printf("QUIT\r\n");
            g_main_loop_quit(loop);
            break;
        }
    }
}

static void *GDBus(void* arg)
{
    bool ret = TRUE;

    loop = g_main_loop_new(NULL, FALSE);
    initGDBusCommunicationForServer();
    g_main_loop_run(loop);
}

int main(int argc, char *argv[])
{
    printf("- - - D-BUS - - -\r\n");

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, (void *)input, NULL);
    pthread_create(&thread2, NULL, (void *)GDBus, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("- - - End - - -\r\n");

    return EXIT_SUCCESS;
}