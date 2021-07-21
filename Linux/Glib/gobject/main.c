#include <glib.h>
#include "student.h"

int main(int argc, char *argv[])
{
    g_printerr("error message!\r\n");

    Example *stu = NULL;
    stu = g_object_new(EXAMPLE_TYPE, NULL);

    g_object_set(stu, "name", "Jane", NULL);
    g_object_set(stu, "id", 128, NULL);

    char *name = NULL;
    g_object_get(stu, "name", &name, NULL);
    g_print("My name is:%s\r\n", name);

    gint id = 0;
    g_object_get(stu, "id", &id, NULL);
    g_print("id:%d\r\n", id);

    g_print("- - - End - - -\r\n");

    return EXIT_SUCCESS;
}