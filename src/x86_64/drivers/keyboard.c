/* CPU control.
 * (C) 2001, 2002, 2003, 2004 Rusty Russell
 *
 * This code is licenced under the GPL.
 */

/*
 * The following two APIs (cpu_maps_update_begin/done) must be used when
 * attempting to serialize the updates to cpu_online_mask & cpu_present_mask.
 */
unsigned char read_keyboard() {
  unsigned char ret;
  asm volatile("inb %1, %0": "=a"(ret): "dN"(0x60));
  return ret;
}

