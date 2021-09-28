#define MSG "Hello World!"

/*
 * The following two APIs (cpu_maps_update_begin/done) must be used when
 * attempting to serialize the updates to cpu_online_mask & cpu_present_mask.
 */
void start_kernel() {
  clear_screen();
  output_screen();
  input_keyboard();
}

