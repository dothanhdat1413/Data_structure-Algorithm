#include <stdio.h>
#include <math.h>

#define NULLL -1000

int tree[15] = {15, 89, 101, 73, 51, 37, 25, 30, 21, NULLL, NULLL, 13, 11, 240, NULLL};

void heap_create(int* tree, int n){
    for(int i = 0; i < n; i++){
        int child = i;
        int parent = (child - 1) / 2;
        while(child > 0 && tree[child] > tree[parent]){
            int temp = tree[child];
            tree[child] = tree[parent];
            tree[parent] = temp;
            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

void tree_print(int* tree, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < pow(2, i); j++){
            printf("%d ", tree[(int)pow(2, i) - 1 + j]);
        }
    printf("\n");
    }
    printf("\n");
}

void heap_sort(int *tree, int n){
    heap_create(tree, n);
    n--;
    if(tree[n] == NULLL){
        printf("%d\n", n);
        if(n == 0) return;
        tree_print(tree, 4);
        heap_sort(tree, n);
    } else {
        printf("%d\n", n);
        printf("%d ", tree[0]);
        printf("%d\n", tree[n]);
        tree_print(tree, 4);
        int temp = tree[0];
        tree[0] = tree[n];
        tree[n] = temp;
        if(n == 0) return;
        heap_sort(tree, n);
    }
}

int main(){
    // tree_print(tree, 4);
    heap_sort(tree, 15);
    tree_print(tree, 4);
    return 0;
}