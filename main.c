/********************************************************************************
* main.c: Demonstration av datastruktur f�r implementering av tryckknappar med
*         PCI-avbrott. I detta fall sker avl�sning av en tryckknapp f�r
*         toggling av en lysdiod via en avbrottsrutin. F�r att g�ra motsvarande
*         objekt synliga i avbrottsrutinen s� anv�nds globala datamedlemmar.
********************************************************************************/
#include "led.h"
#include "button.h"

/* Globala datamedlemmar: */
struct led l1;
struct button b1;

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin f�r PCI-avbrott p� I/O-port B, som i detta
*                    program anropas vid nedtryckning eller uppsl�ppning av
*                    tryckknapp b1. Vid nedtryckning av b1 togglas lysdiod l1.
********************************************************************************/
ISR (PCINT0_vect)
{
   if (button_is_pressed(&b1))
   {
      led_toggle(&l1);
   }

   return;
}

/********************************************************************************
* main: Ansluter en lysdiod till pin 8 / PORTB0 samt en tryckknapp till pin 13
*       / PORTB5, med PCI-avbrott aktiverat f�r toggling av lysdioden. 
********************************************************************************/
int main(void)
{
   led_init(&l1, 8);
   button_init(&b1, 13);
   button_enable_interrupt(&b1);
   
   while (1)
   {

   }

   return 0;
}

