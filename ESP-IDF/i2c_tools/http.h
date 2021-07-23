#ifndef _HTTP_H_
#define _HTTP_H_

#include "freertos/event_groups.h"

EventGroupHandle_t event_group;

void HTTP_Init();

#endif
