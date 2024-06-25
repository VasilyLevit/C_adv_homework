/* Задание 2. Обратная польская запись
Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

Пример No1
Данные на вход: (3 & 5) ^ 4 | 9 
Данные на выход: 3 5 & 4 ^ 9 |

Пример No2
Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 ) 
Данные на выход: 8 2 5 & ^ 6 1 & |  */

// Переделать под подитовые операции &, |, ^
#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#define BUFFER_SIZE 255  // размер очереди вывода
#define STACK_SIZE 255   // размер стека операций

char oper[STACK_SIZE] = {0}; // стек для операций + - * / ( )
int oend = 0; // заполненность стека

// добавление в стек операций
void push(char v) {
    oper[oend++] = v;
}
// извлечение из стек операций
char pop() {
    // проверка на переполение стека
    if(oend <= 0 || oend >= BUFFER_SIZE) {
        fprintf(stderr,"Stack overflow\n");
        exit(1); 
    }
    return oper[--oend]; // возвращаем значение из стека
}

_Bool emptyStack() {
    return oend==0;
}

_Bool isOperator(char c) {
    return c=='&' || c=='^' || c=='|';
}

// проверяем является ли символ цифрой
_Bool isDigit(char c) {
    return ((c >= '0') && (c <= '9'));
}

// определение приоритета операций
int priority(char c) {
    if(c == '^')
        return 1;
    if(c == '&')
        return 2;
    return 0;
}

int main(void)
{
    char c;  // символ из входной строки
    int pos = 0;  // позиция в выходной строке
    char answer[BUFFER_SIZE]={0}; // очередь вывода (массив)
    printf("Input infix string: ");
    char str[1000];  // входящая строка (инфиксная) для выражения
    int len = 0;  //длина введенной строки
    
    // заполнение входящей строки инфиксным выражением
    while( (c = getchar()) != '\n' )
        str[len++] = c;    // кладем из ввода символ в массив
    str[len] = 0;          // термпинируем строку нулем
    
    // printf("%s\n",str);  // проверка принятой строки
    
    // цикл обработки входной строки
    for(int i=0; i<len; i++) {
        // анализатор введенных символов (можно было бы использвоть вместо getchar scanf для перевода символов в число)
        if(isDigit(str[i])) {
            // совтавление числа из последовательности знаков (size - кол-во знаков)
            int number, size = 0;
            for(number = 0; isDigit(str[i]); size++) // пока нам встречаются цифры
                number = number*10 + str[i]-'0'; // -'0' перводим символ в цифру в соответствии с ASCI
            // печать строки (answer + pos = к началу строки прибавляем позию ставя указатель в конец строки)
            sprintf(answer+pos,"%d ", number);
            pos += size+1; //передвигаем позицию в строке на размер числа
        } 
        // если введено не число
        else {
            if(i >= len) // проверка выхода за конец строки
                break;  // если достигли, это и будет результат
            c = str[i];            
            if (isOperator(c)) {
                while( !emptyStack() ) {
                    char top = pop();  // берем оператор с верхнего уровня
                    // проверяем приоритетность операции
                    if(priority(top) >= priority(c)) {
                        sprintf(answer+pos,"%c ",top); // добавлем его в ответ
                        pos += 2; // позиция смещаем на оператор + знак пробела
                    }                    
                    else { // если приоритет текущей операции выше
                        push(top);
                        break; 
                    }
                }
                push(c); // отправляем текущий оператор
            } 
            else if( c=='(' ) {
                push(c);
            } 
            else if( c==')' ) {
                while((c=pop()) != '(') {
                    // добавляем операторы между скобками
                    sprintf(answer+pos,"%c ", c);
                    pos += 2; 
                }
            }              
        }
    }
    while(!emptyStack()) {
        sprintf(answer+pos,"%c ", pop());
        pos += 2; 
    }
    printf("Answer: %s\n", answer);
    return 0; 
}