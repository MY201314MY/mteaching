#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <linux/gpio.h>

int main(int argc, char **argv)
{
	struct gpiohandle_request req;
	struct gpiohandle_data data;
	char chrdev_name[20];
	int fd, ret;

	strcpy(chrdev_name, "/dev/gpiochip0");

	/*  Open device: gpiochip0 for GPIO bank H */
	fd = open(chrdev_name, 0);
	if (fd == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to open %s\n", chrdev_name);

		return ret;
	}

	/* request GPIO line: GPIO_A_13 */
	req.lineoffsets[0] = 13;
	req.flags = GPIOHANDLE_REQUEST_INPUT;
	memcpy(req.default_values, &data, sizeof(req.default_values));
	strcpy(req.consumer_label, "led_gpio_A_13");
	req.lines  = 1;

	ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req);
	if (ret == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to issue GET LINEHANDLE IOCTL (%d)\n", ret);
	}
	if (close(fd) == -1)
		perror("Failed to close GPIO character device file");

	unsigned char i = 0;
	/*  Start led blinking */
	while(i++ < 21) {
		ret = ioctl(req.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data);
		if (ret == -1) {
			ret = -errno;
			fprintf(stderr, "Failed to issue %s (%d)\n",
					"GPIOHANDLE_SET_LINE_VALUES_IOCTL", ret);
		}
        printf("r value:%d\r\n", data.values[0]);
		usleep(1000*1000);

		fprintf(stderr, ".");
	}
	fprintf(stdout, "\nend...\n");
	/*  release line */
	ret = close(req.fd);
	if (ret == -1) {
		perror("Failed to close GPIO LINEHANDLE device file");
		ret = -errno;
	}
	return ret;
}