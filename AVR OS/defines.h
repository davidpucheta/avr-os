/*
 * defines.h
 *
 *  Created on: Jun 9, 2011
 *      Author: david.reyes
 */

/* Frecuencia del CPU */
#define F_CPU 11059200UL

/* UART baud rate */
#define UART_BAUD  9600

//HD44780 LCD port connections
#define HD44780_RS A, 0
#define HD44780_RW A, 1
#define HD44780_E  A, 2
//The data bits have to be not only in ascending order but also consecutive. */
#define HD44780_D4 A, 4

/* Whether to read the busy flag, or fall back to
   worst-time delays. */
#define USE_BUSY_BIT 1
