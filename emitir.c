#include "global.h"

void emitir(int t,int tval){
    switch(t){
        case '+':case '-':case '*':case '/':
            printf("%c\n",t); break;
        case DIV:
            printf("DIV\n"); break;
        case MOD:
            printf("MOD\n"); break;
        case NUM:
            printf("NUM\n"); break;
        case ID:
            printf("%S\n", tab_simb[tval].lexptr); break;
        default:
            printf("token %d, tokenval %d\n",t,tval);
    }
}