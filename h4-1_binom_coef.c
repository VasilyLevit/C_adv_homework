/* Задание 1. Биномиальный коэффициент
Реализовать программу 1-го практического задания с помощью биномиального коэффициента.
Данные на вход: Два целых числа N и M
Данные на выход: Одно целое число – количество вариантов
Пример No1 
Данные на вход: 10 5
Данные на выход: 252
Пример No2 
Данные на вход: 35 5
Данные на выход: 324632
Пример No3 
Данные на вход: 40 10
Данные на выход: 847660528 */

#include <stdio.h>
#include <stdint.h>

u_int64_t binomCoef(int n, int k) {
    u_int64_t res = 1;
    for (int i=n-k+1; i<=n; ++i)
        res *= i;
    for (int i=2; i<=k; ++i)
        res /= i;
    return res; 
}

int main (void)
{
    int n, k;
    printf("Enter two integers separated by a space: ");
    scanf("%d%d", &n, &k);
    printf("%llu\n", binomCoef(n, k));
    return 0;
}