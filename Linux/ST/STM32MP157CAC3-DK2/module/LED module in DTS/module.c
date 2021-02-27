#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>

struct gpio_desc *red, *green;

static int gpio_init_probe(struct platform_device *pdev)
{
   int i = 0;

   printk("GPIO example init\n");

   /* "greenled" label is matching the device tree declaration. OUT_LOW is the value at init */
   green = devm_gpiod_get(&pdev->dev, "greenled", GPIOD_OUT_LOW);

   /* blink of the green led */	
   while (i < 10)
   {
	ssleep(1);
	gpiod_set_value(green, 1);

	ssleep(1);
	gpiod_set_value(green, 0);
	
	i++;
   }

   return(0);
}

static int gpio_exit_remove(struct platform_device *pdev)
{
   printk("GPIO example exit\n");
   
   return(0);
}

/* this structure does the matching with the device tree */
/* if it does not match the compatible field of DT, nothing happens */
static struct of_device_id dummy_match[] = {
    {.compatible = "st,dummy"},
    {/* end node */}
};

static struct platform_driver dummy_driver = {
    .probe = gpio_init_probe,
    .remove = gpio_exit_remove,
    .driver = {
        .name = "dummy_driver",
                .owner = THIS_MODULE,
                .of_match_table = dummy_match,
    }
};
 
module_platform_driver(dummy_driver);

MODULE_AUTHOR("Bernard Puel");
MODULE_DESCRIPTION("Gpio example");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:dummy_driver");