/*
 * leds.c
 *
 *  Created on: Jun 25, 2011
 *      Author: david.reyes
 */


#include <avr/io.h>

void InitLeds(void)
{
//configuracion de los puertos
	DDRD = 0xFF; //Segundero
	PORTD = ~0x00;

	DDRC = 0xFF;//Comandos enc y apag
	PORTC = 0xFF;
}
