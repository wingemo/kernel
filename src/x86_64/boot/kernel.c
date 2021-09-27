#define MSG "Hello World!"

void kernel_entry() {
  clear_screen();
  video_write(MSG);
  keyboard();
}

void clear_screen() {
  char * p = (char * ) 0xb8000;
  int i = 0;
  for (i; i < 4000; i++) {
    * p = '\0';
    p++;
  }
}

void video_write(const unsigned char * string) {
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

unsigned char inb() {
  unsigned char ret;
  asm volatile("inb %1, %0": "=a"(ret): "dN"(0x60));
  return ret;
}

void keyboard() {
  unsigned char inputdata;
  while ((inputdata = inb())) {
    if (inputdata == 0x11) {
      video_write("w");
    }
  }
}
