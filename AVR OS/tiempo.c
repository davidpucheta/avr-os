#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "tiempo.h"

uint8_t Segundos = 0;
uint8_t Minutos = 0;
uint8_t Horas = 0;
uint8_t DD = 1;
uint8_t MM = 1;
uint16_t AA = 0000;

volatile uint16_t cuenta; //tiene que ser de 16 bits porque quermos contar hasta 3600

void initReloj()
{
	TCCR0 = (1 << CS01); // reloj/8 = 1,382,400
	TIMSK = (1<<TOIE0); //habilita interrupcion por overflow en timer
	TCNT0 = 0x00; //ponemos el contador del timer a 0
	cuenta = 0; //el contador tambien a 0
	sei(); //habilitar interrupciones globales

}

void MuestraHora()
{
	printf("%02d:%02d:%02d\n", Horas, Minutos, Segundos);
}

void MuestraFecha()
{
	printf("%02d, %02d ,%04d\n", DD,MM,AA);

}

ISR (TIMER0_OVF_vect)
{
	cuenta++; //cada vez que se desbrode el timer (256) aumentara en uno el contador
	PORTD = ~Segundos; //visualizar el segundero en el puerto D
		
	if (cuenta == 5400) //cuando haya llegado a 5400 el contador
	{					// habra pasado un segundo exacto porque 5400*256= 1,382,400

		fprintf(stderr, "%02d:%02d:%02d\n\n", Horas, Minutos, Segundos);
		cuenta = 0;		//reiniciamos el contador
		Segundos++;		//aumentamos un segundo


		if (Segundos == 59) {
			Segundos = 0;
			Minutos++;

		}

		if (Minutos == 59) {
			Minutos = 0;
			Horas++;
		}

		if (Horas == 24) {
			Horas = 0;
			DD++;
		}

		if (DD == 30) {
			DD = 1;
			MM++;
		}

		if (MM == 12) {
			MM = 1;
			AA++;
		}
	}
}



