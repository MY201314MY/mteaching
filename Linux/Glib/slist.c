#include <glib.h>

int main()
{
    g_print("- - - Glib Example - - -\r\n");

    GSList *slist  = NULL;
    GSList *p = NULL;
    gint array[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    for(int i=0;i<8;i++){
        slist = g_slist_append(slist, &array[i]);
    }

    for(int i=0;i<g_slist_length(slist);i++)
    {
        g_print("value:%d\r\n", *(gint*)g_slist_nth_data(slist, i));
    }

    g_print("\r\n---End---\r\n");


    return 0;
}