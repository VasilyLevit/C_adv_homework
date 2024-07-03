/* Задание 3. Префикс и суффикс
Реализовать программу 3-го практического задания: 
На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. Каждая из строк не превышает по длине 104. В строках не встречаются пробельные символы.
На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

более эффективным способом со сложностью О(n) (см. код в лекции).

Пример No1
Данные на вход: don't_panic nick_is_a_mastodon 
Данные на выход: 3

Пример No2
Данные на вход: python_has_list_comprehensions monty_python 
Данные на выход: 6 */

#include <stdio.h>
#include <string.h>

#define SIZE 10001

int min(int a, int b) {
    return a<b ? a : b;
}

int max(int z[], int n) {
    int max = 0;
    for(size_t i = 0; i < n; i++) {
        if(z[i]> max)
            max = z[i];
    }
    return max;
}

void zFunction2 (char *s, int z[]) {
    int n = strlen(s);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    } 
}

int searchPrefix(char *s1, char *s2)
{
    char s[SIZE+SIZE] = {0}; // массив для склееной из 2х строки
    int z[SIZE+SIZE] = {0};  // массив для z-функции
    size_t s1len = strlen(s1);
    size_t s2len = strlen(s2);
    sprintf(s, "%s#%s", s2, s1); // склеиваем 2е строки в одну
    zFunction2(s, z);
    return max(z + s2len, s1len);
}

int main () {
    char s1[SIZE] = {0};
    char s2[SIZE] = {0};
    printf("Введите подряд 2е строки разделяя пробелом: ");
    scanf("%10000s", s1);
    scanf("%10000s", s2);
    printf("%d\n", searchPrefix(s2,s1));
    return 0; 
}
