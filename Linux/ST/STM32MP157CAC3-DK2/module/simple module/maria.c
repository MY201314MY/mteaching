#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

#define CHAR_LED_CNT    1
#define CHAR_LED_NAME   "maria"
#define OFF             0
#define ON              1

typedef struct{
    dev_t devid;
    struct cdev cdev;
    struct class *class;
    struct device *device;
    int major;
    int minor;
}char_led_dev;

char_led_dev maria;

void led_switch(uint8_t status)
{
    if(status == ON){
        printk("LED ON.\n");
    }else{
        printk("LED OFF.\n");
    }
}

int led_open(struct inode *inode, struct file *filp){
    printk(KERN_INFO "%s - %s - %d\r\n", __FILE__, __func__, __LINE__);
    filp->private_data = &maria;

    return 0;
}

int led_read(struct file *filp, char __user *buf, size_t cnt, loff_t *offt){
    printk(KERN_INFO "%s - %s - %d\r\n", __FILE__, __func__, __LINE__);

    return 0;
}

int led_write(struct file *filp, const char __user *buf, size_t cnt, loff_t *offt){
    int result;
    uint8_t buff[1];
    uint8_t cmd;

    printk(KERN_INFO "%s - %s - %d\r\n", __FILE__, __func__, __LINE__);

    result = copy_from_user(buff, buf, cnt);
    if(result<0){
        printk("kernel write failed!\r\n");
        return -EFAULT;
    }
    cmd = buff[0];

    if(cmd == ON)
        led_switch(ON);
    else
        led_switch(OFF);

    return 0;
}

int led_release(struct inode *inode, struct file *filp){
    printk(KERN_INFO "%s - %s - %d\r\n", __FILE__, __func__, __LINE__);

    return 0;
}
static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = led_open,
    .read    = led_read,
    .write   = led_write,
    .release = led_release
};
static int __init led_init(void)
{
    //create device id
    if(maria.major)
    {
        printk("Done!");
        maria.devid = MKDEV(maria.major, 0);
        register_chrdev_region(maria.devid, CHAR_LED_CNT, CHAR_LED_NAME);   
    }else{
        printk("Do...");
        alloc_chrdev_region(&maria.devid, 0, CHAR_LED_CNT, CHAR_LED_NAME);
        maria.major = MAJOR(maria.devid);
        maria.minor = MINOR(maria.devid);
    }
    printk("maria major=%d, minor=%d", maria.major, maria.minor);
    //init cdev
    maria.cdev.owner = THIS_MODULE;
    cdev_init(&maria.cdev, &fops);
    //add cdev
    cdev_add(&maria.cdev, maria.devid, CHAR_LED_CNT);
    //create class
    maria.class = class_create(THIS_MODULE, CHAR_LED_NAME);
    if(IS_ERR(maria.class)){
        return PTR_ERR(maria.class);
    }
    //create device
    maria.device = device_create(maria.class, NULL, maria.devid, NULL, CHAR_LED_NAME);
    if(IS_ERR(maria.device)){
        return PTR_ERR(maria.device);
    }
    return 0;
}

static void __exit led_exit(void){
    cdev_del(&maria.cdev);
    unregister_chrdev_region(maria.devid, CHAR_LED_CNT);
    device_destroy(maria.class, maria.devid);
    class_destroy(maria.class);
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("mongoose OS");
