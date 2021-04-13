#include <stdio.h>
#include <string.h>

unsigned char crc8_chk_value(unsigned char *message, unsigned char len)
{
    unsigned char crc=0;
    unsigned char i;
    
    while(len--)
    {
        crc ^= *message++;
        for(i = 0;i < 8;i++)
        {
            if(crc & 0x01)
            {
                crc = (crc >> 1) ^ 0x8c;
            }
                else crc >>= 1;
        }
    }
    return crc; 
}

int main(){
	char *p = "A";
	char *d = "{\"crc\":0,\"dveId\":\"1212\",\"frameEnd\":\"0x5A\",\"frameHeader\":\"0xA5\",\"frameLength\":12,\"funCode\":\"1212\",\"params\":{\"age\":\"2\",\"code\":\"6\",\"name\":\"4\"}}";	
	
	printf("CRC8:%d\r\n", crc8_chk_value(p, strlen(p)));
	printf("CRC8:%d\r\n", crc8_chk_value(d, strlen(d))); 
	
	return 0;
}