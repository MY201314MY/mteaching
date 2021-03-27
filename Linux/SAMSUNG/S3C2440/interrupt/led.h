#ifndef __LED_H_
#define __LED_H_

#define LED10_ON  (GPFDAT |= 1<<4)
#define LED10_OFF (GPFDAT &= ~(1<<4))

#define LED11_ON  (GPFDAT |= 1<<5)
#define LED11_OFF (GPFDAT &= ~(1<<5))

#define LED12_ON  (GPFDAT |= 1<<6)
#define LED12_OFF (GPFDAT &= ~(1<<6))

void LED_init();
void LED_test();

#endif
