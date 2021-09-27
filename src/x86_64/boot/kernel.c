#define MSG "Hello World!"
char * c;
void kernel_entry() {
  clear_screen();
  output_screen();
  input_keyboard();
}

void clear_screen() {
  char * p = (char * ) 0xb8000;
  int i = 0;
  for (i; i < 4000; i++) {
    * p = '\0';
    p++;
  }
}

void output_screen(const unsigned char * string) {
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

void input_keyboard() {
  unsigned char inputdata;
  while ((inputdata = inb())) {
    if (inputdata == 0x11) {
      video_write("w");
    } 
    if (inputdata == 0x19) {
      video_write("p");
    } 
  }
}
