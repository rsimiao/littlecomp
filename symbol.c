#include "global.h"
#define STRMAX 999 // tamanho do array de lexemas


char lexemas[STRMAX];
int lastchar = -1; //ultima posicao usada no lexemas
int lastentry = 0; //ultima posicao na tabela de simbolos

int buscar(char s[]){ //retorna a posicao da entrada para s
    
    int p;
    for(p = lastentry; p > 0; p= p -1){
        if(strcmp(tab_simb[p].lexptr,s) == 0)
        return p;
    }
    return 0;
     
}

int insert(char s[], int tok){ //retorna a posicao de entrada para s
    int len;
    len = strlen(s); //calcula o comprimento de s
    if(lastentry + 1 >= SYMMAX)
        erro("tabela de símbolos está cheia");
    if(lastchar + len + 1 >= STRMAX)
        erro("array de lexemas está cheio");
    lastentry = lastentry + 1;
    tab_simb[lastentry].token = tok;
    tab_simb[lastentry].lexptr = &lexemas[lastchar +1];
    strcpy(tab_simb[lastentry].lexptr,s);
    return lastentry;
}