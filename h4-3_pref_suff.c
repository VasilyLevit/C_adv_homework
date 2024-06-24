/* Задание 3. Префикс и суффикс
Реализовать программу 3-го практического задания более эффективным способом со сложностью О(n) (см. код в лекции).

Пример No1
Данные на вход: don't_panic nick_is_a_mastodon 
Данные на выход: 3

Пример No2
Данные на вход: monty_python python_has_list_comprehensions 
Данные на выход: 6 */

// !!! Доработать до O(n) 
#include <stdio.h>
#include <string.h>
enum{maxlength = 10001};
int search_prefix(char*, char*);

int main () {
    char s1[maxlength ], s2[maxlength];
    scanf("%10001s", s1);
    scanf("%10001s", s2);
    printf("%d %d\n", search_prefix(s2,s1), search_prefix(s1,s2));
return 0; }

int search_prefix(char*s1, char*s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l = l1<l2 ? l1 : l2;
    int i1, i2, max=0;
    char c1, c2;
    for (i1 = l1-l; i1<l1; i1++)
    {
        for(i2 = 0; i2<l2; i2++)
        c1 = s1[i1+i2];
        c2 = s2[i2];
#ifdef DEBUG
printf("%c/%c ", c1, c2);
        {
#endif
if(c1 != c2 )
                break;
}
#ifdef DEBUG
printf("\n");
#endif
if(s1[l1-1] == s2[i2-1] && i2 > max)
        max = i2;
} 
return max;
}

// вариант с семинара
// если длина строки n 0(n^3) т.к. strlen имеет сложность O(n)
// лучше занести определение длины переменной в переменную и вызывать её, тогда сложность уменьшиться до O(n^2)
int finMaxPrefSuff(char* str1, char* str2) {
    for(int i = 0; i < strlen(str1); ++i) {
        int match = 1;
        for (j = 0; ((i+j) < strlen(str1)) && j < strlen(str2); ++j) {
            if(str1[i+j] != str2[j]) {
                match = 0;
                break;
            }
        }
        if ((match) && (strlen(str1) - i) <= strlen(str2)) 
            return strlen(str1) - i;
    }
    return 0;
}