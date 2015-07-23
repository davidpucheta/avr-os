/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, upper layer of LCD driver.
 *
 * $Id: lcd.c,v 1.1 2005/12/28 21:38:59 joerg_wunsch Exp $
 */

#include "defines.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>

#include <util/delay.h>

#include "hd44780.h"
#include "lcd.h"

/*
  * Setup the LCD controller.  First, call the hardware initialization
  * function, then adjust the display attributes we want.
  */
 void lcd_init(void)
 {

   hd44780_init();
   /*
    * Clear the display.
    */
   hd44780_outcmd(HD44780_CLR);
   hd44780_wait_ready(1000);
   /*
    * Entry mode: auto-increment address counter, no display shift in
    * effect.
    */
   hd44780_outcmd(HD44780_ENTMODE(1, 0));
   hd44780_wait_ready(1000);
   /*
    * Enable display, activate non-blinking cursor.
    */
   hd44780_outcmd(HD44780_DISPCTL(1, 1, 0));
   hd44780_wait_ready(1000);
 }

 int lcd_putchar(char c, FILE *unused)
 {
   static bool second_nl_seen;
   static uint8_t line=0; //handle multi line displays


   if ((second_nl_seen) && (c != '\n')&&(line==0))
   {
       /*
        * First character after newline was received,  clear display and home cursor.
        */
       hd44780_wait_ready(40);    //40 uS
       hd44780_outcmd(HD44780_CLR);
       hd44780_wait_ready(1600);  //1600 uS
       //obviated the next four lines
       //hd44780_outcmd(HD44780_HOME);
       //hd44780_wait_ready(1600);
       //hd44780_outcmd(HD44780_DDADDR(0));
       //hd44780_wait_ready(1000);
       second_nl_seen=false;
   }
   if (c == '\n')
   {
         if (line==0)
    {
            line++;
            hd44780_outcmd(HD44780_DDADDR(64));
             hd44780_wait_ready(1000);
    }
    else
    {
            second_nl_seen = true;
         line=0;
    }
   }
   else
   {
           hd44780_outdata(c);
      hd44780_wait_ready(40);
   }
   return 0;
 }
