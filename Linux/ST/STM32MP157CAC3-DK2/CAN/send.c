#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int main()
{
	int s;
	struct sockaddr_can addr;
	struct canfd_frame frame;

	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
	{
		printf("socket error.\r\n");
		return 1;
	}

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = if_nametoindex("can0");

	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
	if(bind(s, (struct sockaddr*)&addr, sizeof(addr))<0)
	{
		printf("bind error!\r\n");
		return 1;
	}

	frame.can_id = 12345678;
	frame.len = 3;
	frame.data[0] = 1;
	frame.data[1] = 2;
	frame.data[2] = 3;

	write(s, &frame, 16);

	close(s);

	return 0;
}