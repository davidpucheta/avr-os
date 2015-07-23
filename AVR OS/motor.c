/*
 * motor.c
 *
 *  Created on: Jun 25, 2011
 *      Author: david.reyes
 */
#include <avr/io.h>

void InicializaCtrlMotor(void)
{
	DDRE |= (1<<PE0); // conf pin 0 como salida
	PORTE &= ~(1<<PE0); // inicializamos con el control apagado
}

void GiraIzq(void)
{
	PORTE |= (1<<PE0);
}

void GiraDer(void)
{
	PORTE |= ~(1<<PE0);
}

void ParaMotor(void)
{
	PORTE &= ~(1<<PE0);
}
