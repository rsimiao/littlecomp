#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE  128 //TAMANHO DO BUFFER
#define SYMMAX 100 // tamanho da tabela de simbolos
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

int clinha; // contador de linhas
int tokenval; // Valor atribuido ao token

struct entry{ // formata cada entrada da tabela de simbolos
    char *lexptr;
    int token;
};

struct entry tab_simb[SYMMAX]; //tabela de simbolos

void init();
void emitir(int t,int tval);
void erro(char *m);
int lexan();
void parse();
void expr();
void termo();
void fator();
void reconher(int t);
int buscar(char s[]);
int insert(char s[], int tok);