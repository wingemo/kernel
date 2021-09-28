/* Keyboard Driver.
 * (C) 2021 Philip Wingemo
 *
 */

/*
 * User input from Keyboard
 */
unsigned char input() {
  unsigned char ret;
  asm volatile("inb %1, %0": "=a"(ret): "dN"(0x60));
  return ret;
}

