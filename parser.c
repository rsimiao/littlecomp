#include "global.h"
int lookahead;

void parse(){ //analisa a gramatica e traduz em uma lista de expressoes
    lookahead = lexan();
    while (lookahead != DONE)
    {
        expr(); reconher(';');
    }
    
}

void expr(){
    int t;
    termo();
    while(1){
        switch(lookahead){
            case '+': case '-':
                t = lookahead;
                reconher(lookahead);
                termo();
                emitir(t,NONE);
                continue;
            default:
                return;
        }
    }
}

void termo(){
    int t;
    fator();
    while(1){
        switch (lookahead)
        {
            case '*': case '/': case DIV : case MOD:
                t = lookahead;
                reconher(lookahead);
                fator();
                emitir(t,NONE);
            default:
                return;
        }
    }
}

void fator(){
    switch (lookahead)
    {
        case '(':
            reconher('(');
            expr();
            reconher(')');
            break;
        case NUM:
            emitir(NUM,tokenval);
            reconher(NUM);
            break;
        case ID:
            emitir(ID,tokenval);
            reconher(ID);
            break;
        default:
            erro("erro de sintaxe");
    }
}

void reconher(int t){
    if(lookahead == t){
        lookahead = lexan();
    }
    else{
        erro("erro de sintaxe");
    }
}