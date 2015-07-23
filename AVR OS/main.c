/*
 * main.c
 *
 *  Created on: Jun 9, 2011
 *      Author: david.reyes
 * $Id: stdiodemo.c 1008 2005-12-28 21:38:59Z joerg_wunsch $

 */

#include "defines.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "tiempo.h"
#include "lcd.h"
#include "interprete.h"
#include "motor.h"
#include "leds.h"


static void ioinit(void)
{	//inicializacion de perifericos
	uart_init();
	lcd_init();
	initReloj();
	InicializaCtrlMotor();
	InitLeds();
}


FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main()
{
	stdout = stdin = &uart_str;
	stderr = &lcd_str;
	
	ioinit();
	
	//fprintf(stderr, "Hello world!\n");
	//fprintf(stderr, "Hello world!#2\n");

	prompt();

	return 0;
}
