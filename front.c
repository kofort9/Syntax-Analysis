
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

/*Function declarations */

void addChar();
void getChar();
void getNonBlank();
int lex();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/************************************************/
/* main driver */
main() {
  /* Open the input data file and process its contents */
  if ((in_fp = fopen ("front.in", "r")) == NULL)
    printf("ERROR - cannot open front.in \n");
  else {
    getChar();
    do {
      lex();
    } while( nextToken != EOF);
  }
}

/************************************************/
/* look up - a function to lookup operators and parentheses
                and return the token */
int lookup (char ch) {
  swith(ch) {
    case '(':
      addChar();
      nextToken = LEFT_PAREN;
      break;

    case ')':
      addChar();
      nextToken = RIGHT_PAREN;
      break;

    case '+':
      addChar();
      nextToken = ADD_OP;
      break;

    case '-':
      addChar();
      nextToken = SUB_OP;
      break;

    case '*':
      addChar();
      nextToken = MULT_OP;
      break;

    case '/':
      addChar();
      nextToken = DIV_OP;
      break;

    default:
      addChar();
      nextToken = EOF;
      break;
    }
    return nextToken;
  }

/************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar() {
  if (lexLen <= 98) {
    lexeme[lexLen++] = nextChar;
    lexeme[lexLen] = 0;
  } else {
    printf("Error - lexeme is to long \n");
  }
}

/************************************************/
/* getChar - a function to get the next character of
              input and determine its character class */
void getChar() {
  if ((nextChar = getc(in_fp)) != EOF) {
    if (isalpha(nextChar)) {
      charClass = LETTER;
    } else if (isdigit (nextChar)) {
      charClass = DIGIT;
    } else {
      charClass = UNKNOWN;
    }
  } else {
      charClass = EOF;
  }
}
