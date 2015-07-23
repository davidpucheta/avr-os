/*
 * interprete.c
 *
 *  Created on: Jun 14, 2011
 *      Author: david.reyes
 */
#include <avr/pgmspace.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tiempo.h"
#include "motor.h"
#include "interprete.h"

char comando[30];



void prompt(void)
{
	while (1)
	{
		printf("AVR>");
		gets(comando);
		ProcesaTokens(comando);
	}
}

uint8_t ProcesaTokens(char * buff)
{
	int	idx = 0;
	char *cmd, *ptr, *args[MAX_ARGS];

	if (strtok(buff, DELIMITADOR) == NULL)
		return 1;

	cmd = buff;

	while( (ptr = strtok(NULL, DELIMITADOR) ) != NULL) //inicializamos ptr y evaluamos a la misma vez que no sea nulo
	{
		args[idx] = ptr;

		if (++idx == (MAX_ARGS-1))
		break;
	}

	args[idx] = NULL;

	return EjeCmd(cmd,args);
}


uint8_t EjeCmd(char * c, char ** args)
{
	if (strcmp(c, "enc") == 0) {
		EncLeds(args);
	}

	else if (strcmp(c, "apag") == 0) {
		ApagLeds(args);
	}

	else if (strcmp(c, "hora") == 0) {
		MuestraHora();
	}

	else if (strcmp(c, "fecha") == 0) {
		MuestraFecha();
	}

	else if (strcmp(c, "GiraIzq") == 0) {
		GiraIzq();
	}

	else if (strcmp(c, "GiraDer") == 0) {
		GiraDer();
	}

	else if (strcmp(c, "Para") == 0) {
		ParaMotor();
	}

	else if (strcmp(c, "?") == 0) {
			ImprimeAyuda();
	}

     else if (strcmp(c, "ImpTok") == 0)
     {
        printf("%s\n",c);
        ImprimeTokens(args);
     }
     else if (strcmp(c, "MEM")==0)
     {
    	 mem(args);
     }

	return 0;
}

void EncLeds(char ** args)
{
	uint8_t i;
	i = atoi(*args);
	PORTC = ~i;
}

void ApagLeds(char ** args)
{
	PORTC = 0xFF;
}

void ImprimeTokens(char ** args)
{
    if (args[0]==NULL)
        return;
    else
    {
        int i=0;

        while ( args[i] != NULL )
        {
            printf("%s\n",args[i]);
            i++;
        }
    }
}

void mem(char ** args)
{
	if (args[0]==NULL)
	     return;
	    else
	    {
	        uint8_t Dir_ini, Dir_fin;
	    	char *pm = (char *)0;

	    	Dir_ini = args[0];
	    	Dir_fin = args[1];
	    	pm = 0x60;

	    	while ( pm < 0x70  )
	        {
	            printf("%d\t%d\t%c\n",pm,*pm,*pm);
	            pm++;
	        }
	    }
}

void ImprimeAyuda()
{
	printf_P(PSTR("Comandos:\n "));
	printf_P(PSTR("enc (args) 	Enciende leds puerto C con los argumentos\n"));
	printf_P(PSTR("apag 		Apaga todos los leds del puerto C\n"));
	printf_P(PSTR("hora 		Despliega la hora\n"));
	printf_P(PSTR("fecha 		Despliega la fecha\n"));
	printf_P(PSTR("GiraIzq 		Gira el motor hacia la izquierda\n"));
	printf_P(PSTR("GiraDer 		Gira el motor hacia la derecha\n"));
	printf_P(PSTR("Para 		Detiene el motor\n"));
	printf_P(PSTR("? 			Imprime esta ayuda\n\n"));
	printf_P(PSTR("ImpTok		Imprime los tokens enviados a ImpTok\n"));
}
