#include "student.h"

struct _Example {
    GObject parent;
    gchar *name;
    gint id;
};

enum {
    PROP_NAME=1,
    PROP_ID,
    PROP_NUM
};

G_DEFINE_TYPE(Example, example, G_TYPE_OBJECT);

static GParamSpec *properties[PROP_NUM];

void set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    Example *self = Example_Init(object);

    switch (property_id) {
        case PROP_NAME:
            g_free(self->name);
            self->name = g_strdup(g_value_get_string(value));
            break;
        case PROP_ID:
            self->id = g_value_get_int(value);
            break;
    }
}
void get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    Example *self = Example_Init(object);

    switch (property_id) {
        case PROP_NAME:
            g_value_set_string(value, self->name);
            break;
        case PROP_ID:
            g_value_set_int(value, self->id);
            break;
    }
}

static void example_class_init(ExampleClass *class)
{
    GObjectClass *objectClass = G_OBJECT_CLASS(class);

    objectClass->set_property = set_property;
    objectClass->get_property = get_property;

    properties[PROP_NAME] = g_param_spec_string(
            "name",
            "name",
            "example",
            "Mr.Zhao",
            G_PARAM_READWRITE
            );

    properties[PROP_ID] = g_param_spec_int(
            "id",
            "id",
            "example",
            0,
            255,
            1,
            G_PARAM_READWRITE
    );

    g_object_class_install_properties(objectClass, PROP_NUM, properties);

    g_print("example class init is called!\r\n");
}

static void example_init(Example *self)
{
    g_print("example init is called!\r\n");
}



