/*
Versione corretta dell'esercizio 5

*/

#include <clock.c>
#include <config.c>
#include <adc.c>
#include <led.c>


int adc_result(int canale, char *a);

void main (void){
  int i=0;
  int canale = 1 ;
  char *on="acceso";
  char *off="spento";
attiva_clock(1,'a');
attiva_clock(1,'d');
attiva_clock(2,'a');

gpio_config('a',canale,"analog","default","default","default");
gpio_config('d',15,"output","default","default","default");
gpio_config('d',14,"output","default","default","default");
gpio_config('d',13,"output","default","default","default");
gpio_config('d',12,"output","default","default","default");
//gpio_config('d',5,"output","default","default","default");

double risultato=0.;

while(1){
  risultato=adc_result(canale,on);
  risultato=risultato/4095.;
  //printf("%lf\n",risultato);
  
   if(risultato >= 0.10 && risultato < 0.3){
    led("blue",on);
    led("rosso",off);
    led("arancione",off);
    led("verde",off);
  }
  else if(risultato >= 0.3 && risultato < 0.5){
    led("blue",on);
    led("rosso",on);
    led("arancione",off);
    led("verde",off);
  }
  else if(risultato >= 0.5 && risultato < 0.7){
    led("blue",on);
    led("rosso",on);
    led("arancione",on);
    led("verde",off);
  }
  else if(risultato >= 0.7 && risultato < 1.){
    led("blue",on);
    led("rosso",on);
    led("arancione",on);
    led("verde",on);
  }
  else{
    led("blue",off);
    led("rosso",off);
    led("arancione",off);
    led("verde",off); 
  }    

  }
}


