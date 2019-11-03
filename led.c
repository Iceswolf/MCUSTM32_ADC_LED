void led(char *a, char *b);
#define  GPIO_D_ODR       	(unsigned int*)         (0x40020c14) 
                
#define  arancione              (unsigned int)          (1<<13)
#define  blu         		(unsigned int)          (1<<15)  
#define  rosso 			(unsigned int)   	(1<<14)
#define  verde 			(unsigned int)   	(1<<12)
#define  red                    (unsigned int)   	(1<<5)

void led(char *a, char *b){
unsigned int* puntatore;
puntatore = GPIO_D_ODR;

if(b=="spento"){
	if(a=="blue") *puntatore &= ~ blu;
	else if(a=="rosso") *puntatore &= ~ rosso;	
	else if(a=="verde") *puntatore &= ~ verde;	
	else if(a=="arancione") *puntatore &= ~ arancione;
        else if(a=="redd") *puntatore &= ~ red;	
}

if(b=="acceso"){
	if(a=="blue") *puntatore |= blu;
	else if(a=="rosso") *puntatore |= rosso;	
	else if(a=="verde") *puntatore |= verde;	
	else if(a=="arancione") *puntatore |= arancione;
        else if(a=="redd") *puntatore |= red;	
}

}