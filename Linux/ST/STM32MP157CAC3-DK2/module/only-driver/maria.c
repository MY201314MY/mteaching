#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int __init led_init(void)
{
    return 0;
}

static void __exit led_exit(void){

}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MOON");