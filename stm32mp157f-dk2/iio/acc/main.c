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

    struct iio_device *dev = iio_context_find_device(ctx, "lsm6ds0_accel");
	unsigned int nb_channels = iio_device_get_channels_count(dev);
    printf("channels : %d\r\n", nb_channels);

	double in_accel_scale = 0;
	int ret = iio_device_attr_read_double(dev, "in_accel_scale", &in_accel_scale);
	printf("ret : %d -- value : %lf\r\n", ret, in_accel_scale);

	for(int i=0;i<10000;i++)
	{
		double in_accel_x_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_accel_x_raw", &in_accel_x_raw);

		double in_accel_y_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_accel_y_raw", &in_accel_y_raw);

		double in_accel_z_raw = 0;
		ret = iio_device_attr_read_double(dev, "in_accel_z_raw", &in_accel_z_raw);

	#if 0	
		printf("NO.%06ld : %.4lf -- %.4lf -- %.4lf\r\n", i,
			in_accel_scale * in_accel_x_raw,
			in_accel_scale * in_accel_y_raw, 
			in_accel_scale * in_accel_z_raw);
	#endif

		double angle_1 = atan(in_accel_x_raw/in_accel_z_raw) * 180 / 3.1415926;
		double angle_2 = atan(in_accel_y_raw/in_accel_z_raw) * 180 / 3.1415926;
		printf("%.4f -- %.4f\r\n", angle_1, angle_2);

		usleep(10*1000);
	}

    iio_context_destroy(ctx);

    return 0;
}