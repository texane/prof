/* todo:
   refer to api/samples/memtrace.c for memory
   tracing example. this example shows how to
   inline the log buffer filling code to reduce
   overhead (ie. avoid the callback to be called)
 */


#include "dr_api.h"


/* dr related routines */

static unsigned long insn_count;
static unsigned long read_count;
static unsigned long writ_count;
static unsigned long read_size;
static unsigned long writ_size;

static dr_emit_flags_t event_bb
(
 void* drcontext,
 void* tag,
 instrlist_t* bb,
 bool for_trace,
 bool translating
)
{
  /* refer to dr_ir_instr.h */

  instr_t* insn = instrlist_first(bb);

  for (; insn != NULL; insn = instr_get_next(insn))
  {
    ++insn_count;

    if (instr_reads_memory(insn))
    {
      ++read_count;
      read_size += instr_memory_reference_size(insn);
      dr_printf("read_size:%u\n", instr_memory_reference_size(insn));
    }

    if (instr_writes_memory(insn))
    {
      ++writ_count;
      writ_size += instr_memory_reference_size(insn);
    }
  }

  return DR_EMIT_DEFAULT;
}

static void event_exit(void)
{
  dr_printf("insn_count: %ld\n", insn_count);
  dr_printf("read_count: %ld\n", read_count);
  dr_printf("writ_count: %ld\n", writ_count);
  dr_printf("read_size: %ld\n", read_size);
  dr_printf("writ_size: %ld\n", writ_size);
}

static void event_thread_init(void *drcontext)
{
  /* dr_printf("thread_init\n"); */
}

static void event_thread_exit(void *drcontext)
{
  /* dr_printf("thread_exit\n"); */
}

static void event_post_syscall(void *drcontext, int sysnum)
{
  /* dr_printf("event_syscall\n"); */
}

DR_EXPORT void dr_init(client_id_t id)
{
  insn_count = 0;
  read_count = 0;
  writ_count = 0;
  read_size = 0;
  writ_size = 0;

  dr_register_post_syscall_event(event_post_syscall);
  dr_register_bb_event(event_bb);
  dr_register_thread_init_event(event_thread_init);
  dr_register_thread_exit_event(event_thread_exit);
  dr_register_exit_event(event_exit);
}
