/* Задание 3. Разница между элементами
Напишите программу, которая находит разницу между максимальным и минимальным элементом в дереве. */

/* Решение из семинара 7*/

#include <stdio.h>
#define datatype int

typedef struct tree {
    datatype key;
    struct tree *left, *right;    
} tree;

int max_min(tree *root) {
    // не лучший вариант задавать начальные значения (не учитывают отрицательных значений и максимум не превышает 1000) - лучше присовить значение первого элемента
    static int min = 1000; //MAX 
    static int max = 0;  //MIN

    if(!root)
        return 0;
    
    max = max < root->key ? root->key : max;
    min = min > root->key ? root->key : min;

    max_min(root->left);
    max_min(root->right);

    return max-min;
}

int main(int argc, char ** argv)
{
    tree t[10]={0};
    t[0].left = t+1; t[0].right = t+2; t[0].key = 10;
    t[1].left = t+3; t[1].right = t+4; t[1].key = 5;    
    t[2].left = t+5; t[2].right = t+6; t[2].key = 15;    
    t[3].left = t+7; t[3].key = 3;
    t[4].left = t+8; t[4].key = 7;
    t[5].key = 13;    
    t[6].key = 18;    
    t[7].key = 1; 
    t[8].key = 6;    
    printf("Diff: %d\n", max_min(t));
    return 0;
}