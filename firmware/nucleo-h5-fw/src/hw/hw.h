#ifndef HW_H_
#define HW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#include "led.h"
#include "cli.h"
#include "cli_gui.h"
#include "log.h"
#include "uart.h"
#include "swtimer.h"
#include "gpio.h"
#include "qbuffer.h"



bool hwInit(void);


#ifdef __cplusplus
}
#endif

#endif
