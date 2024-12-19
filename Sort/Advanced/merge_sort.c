#include <stdio.h>

void merge(int* a, int a_n, int* b, int b_n, int* c);
void merge_sort(int* c, int c_n);

int main(){
    int a_n = 4, b_n = 8;

    int a[4] = {15, 30, 201, 303};
    int b[8] = {5, 7, 10, 27, 98, 121, 204, 308};
    int c_n = a_n + c_n;
    int c[12];


    merge(a, a_n, b, b_n, c);

    printf(" \nOut");

    for(int i = 0; i < 12; i++){
        printf("%d ", c[i]);
    }
}

void merge(int* a, int a_n, int* b, int b_n, int*c){
    int j = 0;
    int k = 0;
    for(int i = 0; i < a_n; i++){
        if(j < b_n) {
            while(a[i] >= b[j]){
                c[k] = b[j];
                printf("%d \n", c[k]);
                j++;
                k++;
            }
            c[k] = a[i];
            printf("%d ", c[k]);
            k++;
        } else {
            c[k] = a[i];
            printf("%d ", c[k]);
            k++;
        }
    }    
    while( j < b_n){
        c[k] = b[j];
        printf("%d \n", c[k]);
        j++;
        k++;
    }
}

void merge_sort(int* c, int c_n){
    int pivot = c_n/2;
    merge_sort(c, pivot);
    merge_sort((c + pivot),(c_n-pivot));
    merge(c,pivot,(c+pivot),(c_n-pivot), c);
}