#include <stdio.h>
void swap(int* a, int* b);
void bubble_sort(int* a, int n);
int main(){
    int a[12] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    printf("Bubble sort \n");
    bubble_sort(&a[0],10);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] < a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
        printf ("Lan thu %2d :", (i+1));
        for(int k = 0; k < n; k++ ){
            printf("%3d |", a[k]); 
        }
        printf("\n");
    }
}