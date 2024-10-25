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

    struct iio_device *dev = iio_context_find_device(ctx, "hts221");
	unsigned int nb_channels = iio_device_get_channels_count(dev);
    printf("channels : %d\r\n", nb_channels);

	double in_temp_raw = 0;
	int ret = iio_device_attr_read_double(dev, "in_temp_raw", &in_temp_raw);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_temp_raw); */

	double in_temp_offset = 0;
	ret = iio_device_attr_read_double(dev, "in_temp_offset", &in_temp_offset);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_temp_offset); */

	double in_temp_scale = 0;
	ret = iio_device_attr_read_double(dev, "in_temp_scale", &in_temp_scale);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_temp_scale); */

	double temperature = (in_temp_raw + in_temp_offset) * in_temp_scale;
	printf("temperature : %.2f ℃\r\n", temperature);

	double in_humidityrelative_raw = 0;
	ret = iio_device_attr_read_double(dev, "in_humidityrelative_raw", &in_humidityrelative_raw);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_humidityrelative_raw); */

	double in_humidityrelative_offset = 0;
	ret = iio_device_attr_read_double(dev, "in_humidityrelative_offset", &in_humidityrelative_offset);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_humidityrelative_offset); */

	double in_humidityrelative_scale = 0;
	ret = iio_device_attr_read_double(dev, "in_humidityrelative_scale", &in_humidityrelative_scale);
	/* printf("ret : %d -- value : %lf\r\n", ret, in_humidityrelative_scale); */

	double humidity = (in_humidityrelative_raw + in_humidityrelative_offset) * in_humidityrelative_scale;
	printf("humidity : %.2f %%\r\n", humidity);

    iio_context_destroy(ctx);

    return 0;
}