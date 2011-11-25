#include "dr_api.h"


/* dr related routines */

static volatile int count = 0;

static dr_emit_flags_t event_bb
(
 void* drcontext,
 void* tag,
 instrlist_t* bb,
 bool for_trace,
 bool translating
)
{
  ++count;
  dr_printf("event\n");
  return DR_EMIT_DEFAULT;
}

static void event_exit(void)
{
  dr_printf("fubar: %d\n", count);
}

static void event_thread_init(void *drcontext)
{
  dr_printf("thread_init\n");
}

static void event_thread_exit(void *drcontext)
{
  dr_printf("thread_exit\n");
}

static void event_post_syscall(void *drcontext, int sysnum)
{
  dr_printf("event_syscall\n");
}

DR_EXPORT void dr_init(client_id_t id)
{
  dr_register_post_syscall_event(event_post_syscall);
  dr_register_bb_event(event_bb);
  dr_register_thread_init_event(event_thread_init);
  dr_register_thread_exit_event(event_thread_exit);
  dr_register_exit_event(event_exit);
}
