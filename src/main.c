#include <stdio.h>

#if USE_DYNAMO
#include "dr_config.h"
#include "dr_app.h"
#include "dr_api.h"
#endif


int main(int ac, char** av)
{
  volatile unsigned int i;

#if USE_DYNAMO
  /* per application setup */
  int err = dr_app_setup();
  if (err)
  {
    printf("[!] dr_app_setup() == %d\n", err);
    return -1;
  }
  dr_init(0);
#endif

#if USE_DYNAMO
  /* start of instrumented region */
  dr_app_start();
#endif

  for (i = 0; i < 10; ++i) printf("sys_0\n");

#if USE_DYNAMO
  /* end of instrumented region */
  dr_app_stop();
#endif

  for (i = 0; i < 10; ++i) printf("sys_1\n");

#if USE_DYNAMO
  /* per application finalization */
  dr_app_cleanup();
#endif

  return 0;
}
