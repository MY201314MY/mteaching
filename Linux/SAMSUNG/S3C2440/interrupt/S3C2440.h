/*
    EINTO  -- GPF0
    EINT2  -- GPF2
    EINT11 -- GPG3

    D12 -- GPF6
    D11 -- GPF5
    D10 -- GPF4
*/
#define GPBCON      (*(volatile unsigned long *)0x56000010)
#define GPBDAT      (*(volatile unsigned long *)0x56000014)
#define GPBUP       (*(volatile unsigned long *)0x56000018)

#define GPCCON      (*(volatile unsigned long *)0x56000020)
#define GPCDAT      (*(volatile unsigned long *)0x56000024)
#define GPCUP       (*(volatile unsigned long *)0x56000028)

#define GPDCON      (*(volatile unsigned long *)0x56000030)
#define GPDDAT      (*(volatile unsigned long *)0x56000034)
#define GPDUP       (*(volatile unsigned long *)0x56000038)

#define GPFCON      (*((volatile unsigned int *)0x56000050))
#define GPFDAT      (*((volatile unsigned int *)0x56000054))

#define GPGCON      (*((volatile unsigned int *)0x56000060))
#define GPGDAT      (*((volatile unsigned int *)0x56000064))
#define GPGUP       (*(volatile unsigned long *)0x56000068)

#define GPHCON      (*((volatile unsigned int *)0x56000070))
#define GPHUP       (*((volatile unsigned int *)0x56000078))

#define ULCON0      (*((volatile unsigned int *)0x50000000))
#define UCON0       (*((volatile unsigned int *)0x50000004))
#define UTRSTAT0    (*((volatile unsigned int *)0x50000010))
#define UTXH0       (*((volatile unsigned int *)0x50000023))
#define URXH0       (*(volatile unsigned char *)0x50000024)
#define UBRDIV0     (*((volatile unsigned int *)0x50000028))

#define	TCFG0		(*((volatile unsigned int *)0x51000000))
#define	TCFG1		(*((volatile unsigned int *)0x51000004))
#define	TCON		(*((volatile unsigned int *)0x51000008))
#define	TCNTB0		(*((volatile unsigned int *)0x5100000c))

#define BWSCON      (*((volatile unsigned int *)0x48000000))
#define BANKCON6    (*((volatile unsigned int *)0x4800001C))
#define BANKCON7    (*((volatile unsigned int *)0x48000020))
#define REFRESH     (*((volatile unsigned int *)0x48000024))
#define BANKSIZE    (*((volatile unsigned int *)0x48000028))
#define MRSRB6      (*((volatile unsigned int *)0x4800002C))
#define MRSRB7      (*((volatile unsigned int *)0x48000030))

#define EINTMASK    (*((volatile unsigned int *)0x560000A4))
#define INTMASK     (*((volatile unsigned int *)0x4A000008))
#define PRIORITY    (*((volatile unsigned int *)0x4A00000C))
#define INTOFFSET   (*((volatile unsigned int *)0x4A000014))
#define EINTPEND    (*((volatile unsigned int *)0x560000A8))
#define EXTINT0     (*((volatile unsigned int *)0x56000088))
#define EXTINT1     (*((volatile unsigned int *)0x5600008C))
#define SRCPND      (*((volatile unsigned int *)0x4A000010))
#define INTPND      (*((volatile unsigned int *)0x4A000000))
#define SUBSRCPND   (*((volatile unsigned int *)0x4A000018))
#define INTSUBMSK   (*((volatile unsigned int *)0x4A00001C))


#define LCDCON1     (*(volatile unsigned long *)0x4d000000) //LCD control 1
#define LCDCON2     (*(volatile unsigned long *)0x4d000004) //LCD control 2
#define LCDCON3     (*(volatile unsigned long *)0x4d000008) //LCD control 3
#define LCDCON4     (*(volatile unsigned long *)0x4d00000c) //LCD control 4
#define LCDCON5     (*(volatile unsigned long *)0x4d000010) //LCD control 5
#define LCDSADDR1   (*(volatile unsigned long *)0x4d000014) 
#define LCDSADDR2   (*(volatile unsigned long *)0x4d000018)
#define LCDSADDR3   (*(volatile unsigned long *)0x4d00001c) 
#define REDLUT      (*(volatile unsigned long *)0x4d000020)
#define GREENLUT    (*(volatile unsigned long *)0x4d000024) 
#define BLUELUT     (*(volatile unsigned long *)0x4d000028)
#define DITHMODE    (*(volatile unsigned long *)0x4d00004c) 
#define TPAL        (*(volatile unsigned long *)0x4d000050) 
#define LCDINTPND   (*(volatile unsigned long *)0x4d000054)
#define LCDSRCPND   (*(volatile unsigned long *)0x4d000058) 
#define LCDINTMSK   (*(volatile unsigned long *)0x4d00005c)
#define LPCSEL      (*(volatile unsigned long *)0x4d000060)                         

/*RTC register*/
#define RTCCON      (*(volatile unsigned long *)0x57000040)
#define RTC_ENADLE  (RTCCON |= 1<<0)
#define RTC_DISABLE (RTCCON &= ~(1<<0))

#define BCDSEC      (*(volatile unsigned long *)0x57000070)
#define BCDMIN      (*(volatile unsigned long *)0x57000074)
#define BCDHOUR     (*(volatile unsigned long *)0x57000078)
#define BCDDATE     (*(volatile unsigned long *)0x5700007C)
#define BCDDAY      (*(volatile unsigned long *)0x57000080)
#define BCDMON      (*(volatile unsigned long *)0x57000084)
