void kernel_entry() {
    const char *string = "Welcome to my own os - Philip Wingemo";
    volatile unsigned char *vid = (unsigned char*)0xb8000;
    int index = 0;

    while(*string != 0)
    {
        *(vid) = *string;
        ++string;
        vid+=2;
    }

    while (index < 80 * 25 * 2) {
        *(vid) = ' ';
        vid+=2;
        index += 2;
    }
}
    


