/* Screen Driver.
 * (C) 2021 Philip Wingemo
 *
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
 * Function to clear video buffer array
 */
void clear() {
  char * p = (char * ) 0xb8000;
  int i = 0;
  for (i; i < 4000; i++) {
    * p = '\0';
    p++;
  }
}

