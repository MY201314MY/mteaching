#ifndef GOBJECT_STUDENT_H
#define GOBJECT_STUDENT_H

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE (example_get_type())

/*
 * Example
 *      variable type
 * example
 *      embedded in function name
 * */

G_DECLARE_FINAL_TYPE(Example, example, Example, Init, GObject);


G_END_DECLS

#endif
