#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <linux/input.h>

#define BUTTON_PATH "/dev/input/event1"

int main(int argc, char *argv[])
{
	struct input_event event;

	int ret = 0;
	int fd;

	fd = open(BUTTON_PATH, O_RDONLY);
	if (fd < 0) {
		printf("can't open device");
		return 0;
	}

	while (1)
	{
		/* code */
		ret = read(fd, &event, sizeof(struct input_event));
		if (ret<0)
		{
			printf("failed to read key event:%d\r\n", ret);
		}
		else {
			if(event.code == 103 && event.value == 0)
				printf("button example (maria DB) pressed!\r\n");	
			else if(event.code == 104 && event.value == 0)
				printf("button example (sqlite) pressed!\r\n");	
			else {
	
			}
		}
	}

	close(fd);

	return 0;
}