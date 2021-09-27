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

