#include <stdio.h>

#if USE_DYNAMO
#include "dr_config.h"
#include "dr_app.h"
#include "dr_api.h"
#endif


static void profed_routine(void)
{
  /* scalar product ax = b */

#define N 1024

  register unsigned int i;

  double a[N];
  double x[N];
  volatile double b;

  b = 0;

  for (i = 0; i < N; ++i)
    b += a[i] * x[i];
}


int main(int ac, char** av)
{
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

  profed_routine();
  profed_routine();

#if USE_DYNAMO
  /* end of instrumented region */
  dr_app_stop();
#endif

#if USE_DYNAMO
  /* per application finalization */
  dr_app_cleanup();
#endif

  return 0;
}
