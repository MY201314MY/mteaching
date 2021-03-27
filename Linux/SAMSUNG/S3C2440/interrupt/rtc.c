#include "rtc.h"
#include "uart.h"
#include "S3C2440.h"

unsigned char RTC_SEC(){
    unsigned char temp = 0;
    
    RTC_ENADLE;
    temp = BCDSEC&0X0F ;
    RTC_DISABLE;

    return temp;
}

unsigned char RTC_SEC_BCD(){
    unsigned char temp = 0;
    
    RTC_ENADLE;
    temp = BCDSEC ;
    RTC_DISABLE;

    temp = (temp>>4)&7;

    return temp;
}

unsigned char *RTC_Reader(){
    unsigned char i, index=0, temp[6], buffer[32], *p;
    
    RTC_ENADLE;
    temp[0]=BCDSEC;
    temp[1]=BCDMIN;
    temp[2]=BCDHOUR;
    temp[3]=BCDDATE;
    temp[4]=BCDDAY;
    temp[5]=BCDMON;
    RTC_DISABLE;

    for(i=6;i>0;i--){
        switch(i){
            case 5:buffer[index++]=((temp[5]>>4)&1)+48;buffer[index++]=(temp[5]&0X0F)+48;buffer[index++]='-';break;
            case 6:buffer[index++]=(temp[4]&0X07)+48;buffer[index++]=' ';break;
            case 4:buffer[index++]=((temp[3]>>4)&3)+48;buffer[index++]=(temp[3]&0X0F)+48;break;
            case 3:buffer[index++]=' ';buffer[index++]=((temp[2]>>4)&3)+48;buffer[index++]=(temp[2]&0X0F)+48;break;
            case 2:buffer[index++]=':';buffer[index++]=((temp[1]>>4)&7)+48;buffer[index++]=(temp[1]&0X0F)+48;break;
            case 1:buffer[index++]=':';buffer[index++]=((temp[0]>>4)&7)+48;buffer[index++]=(temp[0]&0X0F)+48;break;
            default: break;
        }
    }
  
    buffer[index++] = '\0';

    return p=buffer;
}

