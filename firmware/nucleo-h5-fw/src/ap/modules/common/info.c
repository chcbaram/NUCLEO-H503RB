#include "ap_def.h"



static bool infoInit(void);
static void cliInfo(cli_args_t *args);

MODULE_DEF(cli) 
{
  .name = "info",
  .priority = MODULE_PRI_LOWEST,
  .init = infoInit
};



bool infoInit(void)
{
  logPrintf("[  ] infoInit()\n");

  cliAdd("info", cliInfo);
  return true;
}



void cliInfo(cli_args_t *args)
{
  bool ret = false;


  if (args->argc == 1 && args->isStr(0, "cpu"))
  {
    while(cliKeepLoop())
    {
      cliPrintf("cpu usage : %3d %%\r", osGetCPUUsage());
      delay(100);
    }
    ret = true;
  }

  if (ret == false)
  {
    cliPrintf("info cpu\n");
  }
}