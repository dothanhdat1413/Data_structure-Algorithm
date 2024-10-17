#include <stdio.h>

void swap(int* a, int* b);
int min(int* a, int n);
void selection_sort(int* a, int n);

int main(){
    int a[12] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    printf("Selection sort \n");
    selection_sort(&a[0], 12);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min(int* a, int n){
    int min = a[0];  
    int j = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < min){
            min = a[i];
            j = i;
        }
    }
    return j;
}

void selection_sort(int* a, int n){
    for(int i = n; i > 0; i-- ){
        int j = min(&a[0], i);
        swap(&a[j], &a[i-1]);
        printf ("Lan thu %2d :", (n-i+1));
        for(int k = 0; k < n; k++ ){
            printf("%3d|", a[k]); 
        }
        printf("\n");
    }
}