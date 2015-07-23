/*
 * interprete.h
 *
 *  Created on: Jun 14, 2011
 *      Author: david.reyes
 */

#ifndef INTERPRETE_H_
#define INTERPRETE_H_


#endif /* INTERPRETE_H_ */

#define MAX_ARGS	6
#define DELIMITADOR " :\r\t\n"

void prompt(void);
uint8_t ProcesaTokens(char *);
uint8_t EjeCmd(char *, char **);
void EncLeds(char **);
void ApagLeds(char **);
void ImprimeAyuda();
void ImprimeTokens( char **);
void mem(char ** args);
