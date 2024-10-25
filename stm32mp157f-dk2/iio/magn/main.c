#include <iio.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("[IIO]\r\n");

    struct iio_context *ctx = iio_create_local_context();
	if (!ctx) {
		printf("create context failed\n");
		exit(0);
	}

    struct iio_device *dev = iio_context_find_device(ctx, "lis3mdl");
	unsigned int nb_channels = iio_device_get_channels_count(dev);
    printf("channels : %d\r\n", nb_channels);

	double in_magn_x_raw = 0;
	int ret = iio_device_attr_read_double(dev, "in_magn_x_raw", &in_magn_x_raw);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_x_raw); */

	double in_magn_x_scale = 0;
	ret = iio_device_attr_read_double(dev, "in_magn_x_scale", &in_magn_x_scale);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_x_scale); */

	double magn_x = (in_magn_x_raw) * in_magn_x_scale;
	printf("magn_x : %.2f\r\n", magn_x);


	double in_magn_y_raw = 0;
	ret = iio_device_attr_read_double(dev, "in_magn_y_raw", &in_magn_y_raw);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_y_raw); */

	double in_magn_y_scale = 0;
	ret = iio_device_attr_read_double(dev, "in_magn_y_scale", &in_magn_y_scale);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_y_scale); */

	double magn_y = (in_magn_y_raw) * in_magn_y_scale;
	printf("magn_y : %.2f\r\n", magn_y);


	double in_magn_z_raw = 0;
	ret = iio_device_attr_read_double(dev, "in_magn_z_raw", &in_magn_z_raw);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_z_raw); */
	double in_magn_z_scale = 0;
	ret = iio_device_attr_read_double(dev, "in_magn_z_scale", &in_magn_z_scale);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_magn_z_scale); */

	double magn_z = (in_magn_z_raw) * in_magn_z_scale;
	printf("magn_z : %.2f\r\n", magn_z);

    iio_context_destroy(ctx);

    return 0;
}