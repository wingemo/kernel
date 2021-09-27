#define MSG "Hello World!"

void kernel_entry() {
    clear_screen();
    video_write(MSG);
}

void clear_screen(){
    char *p = (char *)0xb8000;
    int i = 0 ;                                                                                                                                  
    for(i ; i < 4000 ; i++){                                                                                                                                                       
            *p = '\0';                                                                                                    
            p++ ;                                                                                                         
    }        
}


void video_write(const unsigned char *string){                                                                 
    unsigned char *p = (unsigned char*) string;       
    p++;                                            
    char *c = (char*) (0xb8000);                                                                                                                                                                                         
    while(*p != '\0')                                                                                                    
    {                                                                                                                
            *c = *p;                                                                                                 
            c++ ;                                                                                                       
            *c = 0x07;                                                                                                
            c++ ;     
            p++ ;                                                                                                                                                                                                             
    }    
}

