
/*  front.c - lexical analyzer system for simple arithmetic expression */

#include <stdio.h>
#include <cytype.h>

/* Global declarations */
/* Variables */

int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
