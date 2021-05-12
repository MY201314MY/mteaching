/*
lora ID
SX1278XX

HAL library
*/

void read_ID()
{
    unsigned char id = 0x06;
	unsigned char dat = 0x00;
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, &id, 1, 1000);
    HAL_SPI_Receive(&hspi1, &dat, 1, 1000);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);

	printf("lora ID:0x%02X\r\n", dat);

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi1, &id, &dat, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi1, &id, &dat, 1, 1000);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
	printf("lora ID:0x%02X\r\n", dat);
	
	unsigned char buffer[2] = {0x22, 0x55};
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, buffer, 2, 1000);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, buffer, 1, 1000);
    HAL_SPI_Receive(&hspi1, &dat, 1, 1000);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
	
	printf("0x22:0x%02X\r\n", dat);

}

int W25Q64_Init()
{
	unsigned char ID = 0x90;
	unsigned char temp[5] = {0};
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &ID, 1, 1000);
	
	HAL_SPI_Receive(&hspi2, temp, 5, 1000);
	
	printf("ID: 0x%02X 0x%02X\r\n", temp[3], temp[4]);
	
	return 0;
}

/*
W25QXX
*/

struct rt_spi_device *spi_dev_lora;

int rt_spi_opt_lora_init(void)
{
    rt_hw_spi_device_attach("spi1", "spi10", GPIOD, GPIO_PIN_9);

    spi_dev_lora = (struct rt_spi_device *)rt_device_find("spi10");
    if(spi_dev_lora == RT_NULL) {
        rt_kprintf("W25Q64 Find Failed!");
    } else {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
        cfg.max_hz = 16 * 1000 *1000;
        rt_spi_configure(spi_dev_lora, &cfg);
    }

    return 0;
}

INIT_APP_EXPORT(rt_spi_opt_lora_init);

int lora(uint8_t argc, char **argv){
    uint8_t cmd = 0x06, result = 0;
    rt_spi_send_then_recv(spi_dev_lora, &cmd, 1, &result, 1);
    rt_kprintf("Lora ID: 0x%02X\r\n", result);

    rt_spi_send(spi_dev_lora, &cmd, 1);
    rt_spi_recv(spi_dev_lora, &result, 1);
    rt_kprintf("Lora ID: 0x%02X\r\n", result);

    return RT_EOK;
}

MSH_CMD_EXPORT(lora, lora);

/*
read ID of W25QXX with rt_spi_send_then_recv
*/

int rt_spi_opt_w25q64_init(void)
{
    rt_uint8_t w25x_read_id = 0x90;
    rt_uint8_t id[5] = {0};

    rt_hw_spi_device_attach("spi2", "spi20", GPIOA, GPIO_PIN_8);

    struct rt_spi_device *spi_dev_w25q64;

    spi_dev_w25q64 = (struct rt_spi_device *)rt_device_find("spi20");
    LOG_D("Init...");
    if(spi_dev_w25q64 == RT_NULL) {
        LOG_E("W25Q64 Find Failed!");
    } else {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
        cfg.max_hz = 16 * 1000 *1000;
        rt_spi_configure(spi_dev_w25q64, &cfg);

        rt_spi_send_then_recv(spi_dev_w25q64, &w25x_read_id, 1, id, 5);

        LOG_I("ID: 0x%02X 0X%02X\n", id[3], id[4]);
    }

    return 0;
}

int main(void)
{
    LOG_D("Hello RT-Thread!");
    rt_spi_opt_w25q64_init();
    while (1)
    {
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
