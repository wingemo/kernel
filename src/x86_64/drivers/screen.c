/* CPU control.
 * (C) 2001, 2002, 2003, 2004 Rusty Russell
 *
 * This code is licenced under the GPL.
 */

/*
 *  Function to output data to the standard output device (screen).
 */
void print(const unsigned char * string) {
  unsigned char * p = (unsigned char * ) string;
  p++;
  char * c = (char * )(0xb8000);
  while ( * p != '\0') {
    * c = * p;
    c++;
    * c = 0x07;
    c++;
    p++;
  }
}

/*
 * The following two APIs (cpu_maps_update_begin/done) must be used when
 * attempting to serialize the updates to cpu_online_mask & cpu_present_mask.
 */
void clear() {
  char * p = (char * ) 0xb8000;
  int i = 0;
  for (i; i < 4000; i++) {
    * p = '\0';
    p++;
  }
}

