#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#include "bq35100.h"

#define I2C_BUS  "/dev/i2c-0"
#define I2C_ADDR 0x55

struct bq35100_data bq35100;

static void hex_dump(uint8_t *buffer, size_t size)
{
    uint8_t *p = buffer;
    for(size_t i=0;i<size;i++)
    {
        printf("%02X ", *p);
        p++;
    }
    printf("\n");
}

int bq35100_subcommand_read(int fd, uint16_t subcommand, uint8_t *rxbuff, size_t size)
{
    uint8_t txbuffer[4] = {0x3E, subcommand>>0, subcommand>>8, 0x40};

    write(fd, &txbuffer, sizeof(txbuffer));
    usleep(500*1000);

    return read(fd, rxbuff, size);
}

int bq35100_subcommand_write(int fd, uint16_t subcommand, uint8_t *txbuff, size_t size)
{
    (void)txbuff;
    (void)size;
 
    uint8_t buffer[3] = {0x3E, subcommand>>0, subcommand>>8};

    return write(fd, buffer, sizeof(buffer));
}
/*               9999 */
int bq35100_read(int fd, uint8_t reg, uint8_t *rxbuff, size_t size)
{
    write(fd, &reg, 1);

    return read(fd, rxbuff, size);
}

int bq35100_write(int fd, uint8_t reg, uint8_t *rxbuff, size_t size)
{
    write(fd, &reg, 1);

    return 0;
}

int bq35100_get_status(int fd, bq35100_gauge_status_t status)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_read(fd, BQ35100_CMD_CONTROL, rxbuffer, 2);
    uint16_t ret = rxbuffer[1]<<8 | rxbuffer[0]<<0;
    
    switch(status)
    {
        case BQ35100_STATUS_FLASH:
            return (ret >>15)&0x01;
        break;
        case BQ35100_STATUS_SECURITY:
            return (ret >>13)&0x03;
        break;
        case BQ35100_STATUS_CALMODE:
            return (ret >>12)&0x01;
        break;
        case BQ35100_STATUS_BCA:
            return (ret >>11)&0x01;
        break;
        case BQ35100_STATUS_CCA:
            return (ret >>10)&0x01;
        break;
        case BQ35100_STATUS_LTEN:
            return (ret >>9)&0x01;
        break;
        case BQ35100_STATUS_OCVFAIL:
            return (ret >>8)&0x01;;
        break;
        case BQ35100_STATUS_INITCOMP:
            return (ret >>7)&0x01;;
        break;
        case BQ35100_STATUS_G_DONE:
            return (ret >>6)&0x01;;
        break;
        case BQ35100_STATUS_SOH_ERR:
            return (ret >>5)&0x01;;
        break;
        case BQ35100_STATUS_SOH_MERIT:
            return (ret >>4)&0x01;;
        break;
        case BQ35100_STATUS_EOS_BAD_OCV:
            return (ret >>3)&0x01;;
        break;
        case BQ35100_STATUS_GAS:
            return (ret >>0)&0x01;;
        break;
        default: break;
    }

    return -1;
}

int bq35100_set_security_mode(int fd, bq35100_security_mode_t security){
    uint8_t i = 0;
    uint8_t current_security = bq35100_get_status(fd, BQ35100_STATUS_SECURITY);

    uint8_t txbuffer[32] = {0};
    printf("--------------------------:%d\r\n", current_security);
    if(current_security != 0x00)
    {
        for(i=0;i<8;i++)
        {
            switch (security)
            {
                case BQ35100_SECURITY_UNSEALED:
                    txbuffer[0] = 0x3E;
                    txbuffer[1] = (uint8_t)(BQ35100_DEFAULT_SEAL_CODES>>16);
                    txbuffer[2] = (uint8_t)(BQ35100_DEFAULT_SEAL_CODES>>24);
                    write(fd, txbuffer, 3);
                    usleep(100*1000);

                    txbuffer[0] = 0x3E;
                    txbuffer[1] = (uint8_t)(BQ35100_DEFAULT_SEAL_CODES>>0);
                    txbuffer[2] = (uint8_t)(BQ35100_DEFAULT_SEAL_CODES>>8);
                    write(fd, txbuffer, 3);
                    usleep(100*1000);
                break;
                case BQ35100_SECURITY_FULL_ACCESS:
                    txbuffer[0] = 0x3E;
                    txbuffer[1] = (uint8_t)(BQ35100_FULL_ACCESS_CODES>>16);
                    txbuffer[2] = (uint8_t)(BQ35100_FULL_ACCESS_CODES>>24);
                    write(fd, txbuffer, 3);
                    usleep(100*1000);

                    txbuffer[0] = 0x3E;
                    txbuffer[1] = (uint8_t)(BQ35100_FULL_ACCESS_CODES>>0);
                    txbuffer[2] = (uint8_t)(BQ35100_FULL_ACCESS_CODES>>8);
                    write(fd, txbuffer, 3);
                    usleep(100*1000);
                break;
                case BQ35100_SECURITY_SEALED:
                    txbuffer[0] = 0x3E;
                    txbuffer[1] = (uint8_t)(BQ35100_CTRL_SEALED>>0);
                    txbuffer[2] = (uint8_t)(BQ35100_CTRL_SEALED>>8);
                    write(fd, txbuffer, 3);
                    usleep(100*1000);
                break;
                default: break;
            }

            usleep(1000*1000);

            current_security = bq35100_get_status(fd, BQ35100_STATUS_SECURITY);

            if(current_security == security)
            {
                printf("security set success.\r\n");
                break;
            }else
            {
                printf("C:%d -- E:%dretry...\r\n", current_security, security);
            }
        }
    }

    return i==8?-1:0;
}

static int bq35100_gauge_start(int fd)
{
    int status = bq35100_get_status(fd, BQ35100_STATUS_GAS);
    printf("GA : %d\n", status);
    if(status == 0)
    {
        bq35100_subcommand_write(fd, BQ35100_CTRL_GAUGE_START, NULL, 0);
        for(uint8_t i=0;i<8;i++)
        {
            usleep(100*1000);
            status = bq35100_get_status(fd, BQ35100_STATUS_GAS);
            if(status == 1)
            {
                printf("Gauge is in ATCIVE mode.\r\n");
                break;
            }
        }
    }else{
        printf("Gauge has been in ATCIVE mode.\r\n");
    }
    return 0;
}

static int bq35100_gauge_stop(int fd)
{
	int status = bq35100_get_status(fd, BQ35100_STATUS_GAS);
    printf("GA : %d\n", status);
    if(status == 1)
    {
        bq35100_subcommand_write(fd, BQ35100_CTRL_GAUGE_STOP, NULL, 0);
        for(uint8_t i=0;i<8;i++)
        {
            usleep(1000*1000);
            status = bq35100_get_status(fd, BQ35100_STATUS_GAS);
            if(status == 0)
            {
                printf("Gauge is in INATCIVE mode.\r\n");
                break;
            }
        }
    }else{
        printf("Gauge has been in INATCIVE mode.\r\n");
    }

	return 0;
}

int bq35100_get_temperature(int fd, short *temperature)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_read(fd, BQ35100_CMD_TEMPERATURE, rxbuffer, 2);
    *temperature = rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_accumulated_capacity(int fd, int *acc_capacity)
{
    uint8_t rxbuffer[4] = {0};

    bq35100_read(fd, BQ35100_CMD_ACCUMULATED_CAPACITY, rxbuffer, 4);
    hex_dump(rxbuffer, 4);
    *acc_capacity = rxbuffer[3]<<24 | rxbuffer[2]<<16 | rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_design_capacity(int fd, uint16_t *design_capacity)
{
    uint8_t rxbuffer[4] = {0};

    bq35100_read(fd, BQ35100_CMD_DESIGN_CAPACITY, rxbuffer, 2);
    *design_capacity = rxbuffer[1]<<8 | rxbuffer[0]<<0;
    hex_dump(rxbuffer, 2);

    return 0;
}

int bq35100_get_voltage(int fd, short *voltage)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_read(fd, BQ35100_CMD_VOLTAGE, rxbuffer, 2);
    *voltage = rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_current(int fd, short *current)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_read(fd, BQ35100_CMD_CURRENT, rxbuffer, 2);
    *current = rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_battery_status(int fd, uint8_t *battery_status)
{
    uint8_t rxbuffer[1] = {0};

    bq35100_read(fd, BQ35100_CMD_BATTERY_STATUS, rxbuffer, 1);
    *battery_status = rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_battery_alert(int fd, uint8_t *battery_alert)
{
    uint8_t rxbuffer[1] = {0};

    bq35100_read(fd, BQ35100_CMD_BATTERY_ALERT, rxbuffer, 1);
    *battery_alert = rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_fw_version(int fd, uint16_t *version)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_subcommand_read(fd, BQ35100_CTRL_FW_VERSION, rxbuffer, 2);
    *version = rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_get_hw_version(int fd, uint16_t *version)
{
    uint8_t rxbuffer[2] = {0};

    bq35100_subcommand_read(fd, BQ35100_CTRL_HW_VERSION, rxbuffer, 2);
    *version = rxbuffer[1]<<8 | rxbuffer[0]<<0;

    return 0;
}

int bq35100_new_battery(int fd)
{
    printf("++++battery++++");
    bq35100_subcommand_write(fd, BQ35100_CTRL_NEW_BATTERY, NULL, 0);
    printf("----0000000----");
    
    return 0;
}

int bq35100_sample(int fd)
{
    bq35100_get_accumulated_capacity(fd, &bq35100.acc_capacity);
    printf("AccumulatedCapacity : %d\r\n", bq35100.acc_capacity);

    bq35100_get_temperature(fd, &bq35100.temperature);
    printf("Temperature : %d\r\n", bq35100.temperature);

    bq35100_get_voltage(fd, &bq35100.voltage);
    printf("Voltage : %d\r\n", bq35100.voltage);

    bq35100_get_current(fd, &bq35100.current);
    printf("Current : %d\r\n", bq35100.current);

    printf("\r\n");

    return 0;
}

static uint8_t bq35100_compute_checksum(const char *data, size_t length)
{
	uint8_t checksum = 0;
	uint8_t x = 0;

	if (data) {
		for (; x < length; x++) {
			checksum += *data;
			data++;
		}

		checksum = 0xFF - checksum;
	}

	return checksum;
}

int bq35100_extended_data_read(int fd, uint16_t address, uint8_t *rxbuff, size_t size)
{
    uint8_t buffer[36] ={0};
    
    bq35100_subcommand_write(fd, address, NULL, 0);
    sleep(1);
    bq35100_read(fd, 0x3E, buffer, sizeof(buffer));

    /* 
    D0 41 FF FF FF FF 0B A6 
    02 58 02 02 26 0A 8C 02 
    0B B8 00 32 02 00 64 00 
    05 00 00 0A 00 00 7F FF 
    0A F8 3B 24 
        
    */
    
    if((buffer[0] != (uint8_t)(address>>0)) || (buffer[1] != (uint8_t)(address>>8)))
    {
        printf("address doesn't match.\r\n");
    }

    if(buffer[34] != bq35100_compute_checksum(buffer, buffer[35]-2))
    {
        printf("checksum doesn't match.\r\n");
    }

    memcpy(rxbuff, buffer+2, size);

    return 0;
}

int bq35100_extended_data_write(int fd, uint16_t address, uint8_t *txbuff, size_t size)
{
    uint8_t buffer[36] = {0};

    buffer[0] = BQ35100_CMD_MAC_DATA_LEN;
    buffer[1] = 0x00;
    write(fd, buffer, 2);
    
    buffer[0] = BQ35100_CMD_MAC_CONTROL;
    buffer[1] = address>>0;
    buffer[2] = address>>8;
    memcpy(buffer+3, txbuff, size);
    write(fd, buffer, 3+size);

    buffer[0] = BQ35100_CMD_MAC_DATA_SUM;
    buffer[1] = bq35100_compute_checksum(buffer+1, size+2);
    write(fd, buffer, 2);

    buffer[0] = BQ35100_CMD_MAC_DATA_LEN;
    buffer[1] = size + 4;

    write(fd, buffer, 2);
    
    return 0;
}

int bq35100_set_design_capacity(int fd, uint16_t design_capacity)
{
    uint8_t txbuffer[2] = {design_capacity>>8, design_capacity>>0};
    hex_dump(txbuffer, 2);
    uint8_t status = bq35100_get_status(fd, BQ35100_STATUS_FLASH);
    bq35100_extended_data_write(fd, BQ35100_FLASH_CELL_DESIGN_CAPACITY_MAH, txbuffer, 2);
    usleep(200*1000);
    status = bq35100_get_status(fd, BQ35100_STATUS_FLASH);
    printf("F BAT DETECT : %d\r\n", status);

    bq35100_get_design_capacity(fd, &bq35100.design_capacity);
    printf("DesignCapacity : %d\r\n", bq35100.design_capacity);
    
    return 0;
}

int main(int argc, char *argv[])
{
    int fd = open(I2C_BUS, O_RDWR);
    if(fd < 0)
        printf("open \"%s\" failed.\n", I2C_BUS);
    
    if(ioctl(fd, I2C_SLAVE_FORCE, I2C_ADDR) < 0)
        printf("set slave address failed.\n");

    uint8_t rxbuffer[64] = {0};
    uint8_t txbuffer[64] = {0};

    printf("=========================================================\r\n");
    bq35100_subcommand_read(fd, BQ35100_CTRL_DEVICE_TYPE, rxbuffer, 2);
    uint16_t id = rxbuffer[0]<<8 | rxbuffer[1]<<0;
    if(id != BQ35100_DEVICE_TYPE_ID)
    {
        printf("bq35100 not found. should be:0x%04X, but is:0x%04X\r\n", BQ35100_DEVICE_TYPE_ID, id);
        return -1;
    }

    printf("bq35100 init success.\n");

    bq35100_get_fw_version(fd, &bq35100.fw_version);
    printf("FW : %04X\r\n", bq35100.fw_version);

    bq35100_get_hw_version(fd, &bq35100.hw_version);
    printf("HW : %04X\r\n", bq35100.hw_version);
    /*
        bq35100_extended_data_read(fd, BQ35100_FLASH_FULL_UNSEAL_STEP1, rxbuffer, 4);
        hex_dump(rxbuffer, 4);
    */
#if 0
    bq35100_set_security_mode(fd, BQ35100_SECURITY_SEALED);
    bq35100_set_security_mode(fd, BQ35100_SECURITY_UNSEALED);

    bq35100_set_design_capacity(fd, 2802);

    bq35100_extended_data_read(fd, BQ35100_FLASH_CELL_DESIGN_CAPACITY_MAH, rxbuffer, 2);
    printf("CAP Read : ");
    hex_dump(rxbuffer, 2);

    bq35100_set_security_mode(fd, BQ35100_SECURITY_SEALED);
#endif
#if 1
    bq35100_get_design_capacity(fd, &bq35100.design_capacity);
    printf("DesignCapacity : %d\r\n", bq35100.design_capacity);

    bq35100_get_battery_status(fd, &bq35100.battery_status);
    printf("BatteryStatus : %02X\r\n", bq35100.battery_status);

    bq35100_get_battery_alert(fd, &bq35100.battery_alert);
    printf("BatteryAlert : %02X\r\n", bq35100.battery_alert);
#if 0
    printf("security mode.\r\n");
    bq35100_set_security_mode(fd, BQ35100_SECURITY_SEALED);
    bq35100_set_security_mode(fd, BQ35100_SECURITY_UNSEALED);
    bq35100_set_security_mode(fd, BQ35100_SECURITY_FULL_ACCESS);
    bq35100_set_security_mode(fd, BQ35100_SECURITY_SEALED);
#endif
    //bq35100_new_battery(fd);
    //sleep(10);

    bq35100_gauge_start(fd);

    uint8_t count = 0;
    while (count<10)
    {
        count++;
        bq35100_sample(fd);

        sleep(1);
    }
    
    bq35100_gauge_stop(fd);
#endif
    int result = close(fd);
    if(result < 0){
        printf("close failed!\n");
    }

    return 0;
}