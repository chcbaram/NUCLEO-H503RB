#ifndef BSP_H_
#define BSP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "def.h"


#include "stm32h5xx_hal.h"

#define assert   assert_param




bool bspInit(void);

void logPrintf(const char *fmt, ...);
void delay(uint32_t time_ms);
uint32_t millis(void);
void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif
