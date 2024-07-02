/* Задание 2. Сумма всех элементов
Напишите программу, которая возвращает сумму всех элементов в дереве. */

#include <stdio.h>

typedef struct tree {
    int value;
    struct tree *left, *right;
} tree;

int sum(tree *root) {
    if (!root)
        return 0;
    return root->value + sum(root->left) + sum(root->right);
}

int main(int argc, char ** argv)
{
    tree t[10]={0};
    t[0].left = t+1; t[0].right = t+2; t[0].value = 10;
    t[1].left = t+3; t[1].right = t+4; t[1].value = 5;    
    t[2].left = t+5; t[2].right = t+6; t[2].value = 15;    
    t[3].left = t+7; t[3].value = 3;
    t[4].left = t+8; t[4].value = 7;
    t[5].value = 13;    
    t[6].value = 18;    
    t[7].value = 1; 
    t[8].value = 6;
    printf("Sum: %d\n", sum(t));
    return 0;
}