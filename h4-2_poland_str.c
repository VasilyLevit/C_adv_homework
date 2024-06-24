/* Задание 2. Обратная польская запись
Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

Пример No1
Данные на вход: (3 & 5) ^ 4 | 9 
Данные на выход: 3 5 & 4 ^ 9 |

Пример No2
Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 ) 
Данные на выход: 8 2 5 & ^ 6 1 & |  */

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 255
#define STACK_SIZE 255

char oper[STACK_SIZE] = {0}; // стек для операций + - * / ( )
int oend=0; // заполненность стека

void push(char v) {
    oper[oend++] = v;
}

char pop() {
    if(oend <= 0 || oend >= BUFFER_SIZE) {
        fprintf(stderr,"Stack overflow\n");
        exit(1); 
    }
    return oper[--oend];
}

_Bool emptyStack() {
    return oend==0;
}

_Bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

// определение приоритета операций
int priority(char c) {
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    return 0;
}

int main(void)
{
    char c;
    int i=0, isMinus = 0;
    int ret, pos=0;
    int number;
    char answer[BUFFER_SIZE]={0};
    printf("Input infix string: ");
    while( (ret = scanf("%d",&number))!=EOF ) {
        int p=0;
        if(ret==1) {
            sprintf(answer+pos,"%d %n",number,&p);
            pos += p;
        } 
        else {
            if(scanf("%c",&c)==EOF) 
                break;
            if(isOperator(c)) {
                while( !emptyStack() ) {
                    char top = pop();
                    int p=0;
                    if(priority(top) >= priority(c)) {
                        sprintf(answer+pos,"%c %n",top,&p);
                        pos += p;
                    } 
                    else { // isOperator(top) == false
                        push(top);
                        break; 
                    }
                }
                push(c);
            } 
            else if( c=='(' ) {
                push(c);
            } 
            else if( c==')' ) {
                while( (c=pop()) != '(' ) {
                    int p=0;
                    sprintf(answer+pos,"%c %n",c,&p);
                    pos += p; 
                }
            }
        } 
    }
    while( !emptyStack() ) {
        int p=0;
        sprintf(answer+pos,"%c %n", pop(), &p);
        pos += p; 
    }
    printf("Answer: %s\n",answer);
    return 0; 
}