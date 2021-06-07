#include <iio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
static void channel_has_attr(struct iio_channel *chn, const char *attr)
{
	unsigned int i, nb = iio_channel_get_attrs_count(chn);
	printf("attributes:%d\r\n", nb);
	for (i = 0; i < nb; i++){
		printf("channel attr = %s\n", iio_channel_get_attr(chn, i));
}
*/
/*
static double get_channel_value(struct iio_channel *chn)
{
	char buf[1024];
	double val;
 
	if (channel_has_attr(chn, "processed")) {
		iio_channel_attr_read(chn, "processed", buf, sizeof(buf));
		val = strtod(buf, NULL);
	} else {
		iio_channel_attr_read(chn, "raw", buf, sizeof(buf));
		val = strtod(buf, NULL);
 
		if (channel_has_attr(chn, "offset")) {
			iio_channel_attr_read(chn, "offset", buf, sizeof(buf));
			val += strtod(buf, NULL);
		}
 
		if (channel_has_attr(chn, "scale")) {
			iio_channel_attr_read(chn, "scale", buf, sizeof(buf));
			val *= strtod(buf, NULL);
		}
	}
 
	val = val * 5 / 32768.0;
	return val;
}
*/

static double get_channel_value(struct iio_channel *chn)
{
	char buf[1024];

	iio_channel_attr_read(chn, "raw", buf, sizeof(buf));
	printf("read:%s\r\n", buf);

	iio_channel_attr_read(chn, "powerdown_mode", buf, sizeof(buf));
	printf("read:%s\r\n", buf);

	iio_channel_attr_read(chn, "scale", buf, sizeof(buf));
	printf("read:%s\r\n", buf);

	iio_channel_attr_read(chn, "powerdown", buf, sizeof(buf));
	printf("read:%s\r\n", buf);

	iio_channel_attr_read(chn, "powerdown_mode_available", buf, sizeof(buf));
	printf("read:%s\r\n", buf);
 
	return 120;
}

int main(int argc, char *argv[])
{
    printf("mongoose OS.\r\n");

    struct iio_context *ctx;
	unsigned int i, nb_devices;
	unsigned int nb_channels;
	double channel_value;
	struct iio_device *dev;
	struct iio_channel *chn;

    ctx = iio_create_local_context();
	if (!ctx) {
		printf("create context failed\n");
		exit(0);
	}

    nb_devices = iio_context_get_devices_count(ctx);
    printf("device count:%d\r\n", nb_devices);

    dev = iio_context_get_device(ctx, 0);
	nb_channels = iio_device_get_channels_count(dev);
    printf("channels:%d\r\n", nb_channels);

    chn = iio_device_get_channel(dev, 0);

	channel_value = get_channel_value(chn);

    iio_context_destroy(ctx);

	printf("---End---");

    return 0;
}
