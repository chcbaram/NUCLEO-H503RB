#ifndef EXTIO_H_
#define EXTIO_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "hw_def.h"


#ifdef _USE_HW_EXTIO


#define EXTIO_MAX_CH            HW_EXTIO_MAX_CH




bool extioInit(void);
void extioPinWrite(uint8_t ch, uint8_t value);
uint8_t extioPinRead(uint8_t ch);
void extioPinToggle(uint8_t ch);


#endif

#ifdef __cplusplus
 }
#endif


#endif 