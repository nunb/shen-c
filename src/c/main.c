#include "boolean.h"
#include "environment.h"
#include "extension.h"
#include "kl.h"
#include "loop.h"
#include "number.h"
#include "object.h"
#include "primitive.h"
#include "repl.h"
#include "stream.h"
#include "string.h"
#include "symbol.h"
#include "variable.h"
#include "vector.h"

static inline void initialize (void)
{
  initialize_boolean_objects();
  initialize_empty_kl_list();
  initialize_empty_vector();
  initialize_empty_loop_frame_pair();
  initialize_start_clock();
  initialize_trapped_kl_exception_stack();
  initialize_loop_frame_stack();
  initialize_symbol_name_table();
  register_stream_symbol_objects();
  register_overwrite_symbol_objects();
  register_system_symbol_objects();
  register_primitive_kl_functions();
  register_extension_primitive_kl_functions();
  initialize_read_buffer();
  initialize_std_stream_objects();
  register_global_variables();
}

int main (void)
{
  GC_init();
  initialize();
  load_shen_kl_files();
  run_shen_repl();

  return 0;
}
