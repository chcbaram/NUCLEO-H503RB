#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V231029R1"
#define _DEF_BOARD_NAME           "NUCLEO-H5-FW"



#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define      HW_UART_MAX_CH         1
#define      HW_UART_CH_DEBUG       _DEF_UART1

#define _USE_HW_LOG
#define      HW_LOG_CH              _DEF_UART1

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    48
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    8
#define      HW_CLI_LINE_BUF_MAX    64

#define _USE_HW_CLI_GUI
#define      HW_CLI_GUI_WIDTH       80
#define      HW_CLI_GUI_HEIGHT      24





typedef enum
{
  mGPIO_Spare1 = 0,
  mGPIO_Spare2    ,
  mGPIO_Spare3    ,
  mOut_Watchdog   ,
  mOut_Reg_On     ,
  mOut_Sol_13V    ,
  mOut_Sol_21V    ,
  mOut_Sol_2WAY1  ,
  mOut_Sol_2WAY2  ,
  mOut_Sol_2WAY3  ,
  mOut_Sol_2WAY4  ,
  mOut_Sol_3WAY1  ,
  mOut_Sol_3WAY2  ,
  GPIO_PIN_MAX
} GpioPinName_t;



#endif
