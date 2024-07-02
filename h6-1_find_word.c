/* Задание 1. Поиск первого и последнего слова
Используя код задачи 1, написать программу поиска первого и последнего слова в строке.
Пример No1 
Данные на входе: efg abcd zzz.
Данные на выходе: efg zzz
Пример No2 
Данные на входе: fffff kkkkkk a.
Данные на выходе: fffff a. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 2000

typedef struct list {
    char *word;
    struct list *next;
}list;

list* insert2(char *value, list *head) {
    list *res = (list*)calloc(1, sizeof(list));
    int len = strlen(value);  //определяем размер строки
    res->word = malloc(len+1);  //выделяем память под строку
    strcpy(res->word, value);  //копируем строку в память
    res->next = head;  //смещаем указатель на следующий
    return res;
}

void print_list(list *head) {
    for (list *i = head; i!=NULL; i=i->next)
        printf("%s ", i->word);
    putchar('\n');
}

void delete_list(list *l) {
    list *c =l;
    list *n;
    while(c != NULL){
        n = c->next;
        free(c->word); //Очищаем память под слово
        free(c);
        c = n;
    } 
}

void print_first_last(struct list *head) {
    list *last = head;  //сохраняем первый элемент в last который будем менять
    while (last->next != (struct list *)NULL)
        last = last->next;
    printf("Output: %s ", last->word);
    printf("%s\n", head->word);
}

int main(int argc, char** argv) {
    list *w_list=NULL;
    char word[STR_SIZE]="";
    int ch = ' ';
    int i=0;
    printf("Inpit: ");
    while(EOF != (ch = getchar())){
        switch(ch){
            case '.':
            case ' ':
                word[i] = '\0';
                w_list  = insert2(word, w_list);
                i=0;
            break;
            default:
                word[i++] = ch;
                if(i>=STR_SIZE)
                    i=0;//Защита от переполнения строки
        }
        if('.' == ch)
            break;
    }

#ifdef DEBUG
    print_list(w_list);
#endif
    
    print_first_last(w_list);
    delete_list(w_list);
    return 0; 
}
