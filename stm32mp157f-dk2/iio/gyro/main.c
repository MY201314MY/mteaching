#include <iio.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
    printf("[IIO]\r\n");

    struct iio_context *ctx = iio_create_local_context();
	if (!ctx) {
		printf("create context failed\n");
		exit(0);
	}

    struct iio_device *dev = iio_context_find_device(ctx, "lsm6ds0_gyro");
	unsigned int nb_channels = iio_device_get_channels_count(dev);
    printf("channels : %d\r\n", nb_channels);

	double in_anglvel_scale = 0;
	int ret = iio_device_attr_read_double(dev, "in_anglvel_scale", &in_anglvel_scale);
	printf("ret : %d -- value : %lf\r\n", ret, in_anglvel_scale);

	for(int i=0;i<10000;i++)
	{
		double in_anglvel_x_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_anglvel_x_raw", &in_anglvel_x_raw);

		double in_anglvel_y_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_anglvel_y_raw", &in_anglvel_y_raw);

		double in_anglvel_z_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_anglvel_z_raw", &in_anglvel_z_raw);
	
		printf("NO.%06ld : %.4lf -- %.4lf -- %.4lf\r\n", i,
			in_anglvel_scale * in_anglvel_x_raw,
			in_anglvel_scale * in_anglvel_y_raw, 
			in_anglvel_scale * in_anglvel_z_raw);

		usleep(10*1000);
	}

    iio_context_destroy(ctx);

    return 0;
}