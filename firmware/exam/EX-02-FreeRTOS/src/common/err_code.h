#ifndef ERR_CODE_H_
#define ERR_CODE_H_



typedef enum
{
  OK                            = 0x0000,
  ERR_MEMORY                    = 0x0001,
  ERR_FULL                      = 0x0002,
  ERR_EMPTY                     = 0x0003,
  ERR_NULL                      = 0x0004,
  ERR_INVAILD_INDEX             = 0x0005,

  ERR_BOOT_WRONG_CMD            = 0x000A,
  ERR_BOOT_LED                  = 0x000B,
  ERR_BOOT_FLASH_ERASE          = 0x000C,
  ERR_BOOT_WRONG_RANGE          = 0x000D,
  ERR_BOOT_FLASH_WRITE          = 0x000E,
  ERR_BOOT_BUF_OVF              = 0x000F,
  ERR_BOOT_INVALID_FW           = 0x0010,
  ERR_BOOT_FW_CRC               = 0x0011,
  ERR_BOOT_JUMP_TO_FW           = 0x0012,
  ERR_BOOT_TAG_MAGIC            = 0x0013,
  ERR_BOOT_TAG_SIZE             = 0x0014,
  ERR_BOOT_FLASH_READ           = 0x0015,

} ErrCode_t;


#endif 