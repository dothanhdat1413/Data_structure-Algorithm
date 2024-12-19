#include <stdio.h>

#define y_1920 0
#define y_1970 50

int birth[51] = {45, 44, 72, 5, 82, 77, 15, 56, 22, 27, 6, 91, 69, 59, 69, 16, 69, 1, 76, 58, 88, 45, 66, 5, 86, 38, 100, 3, 80, 34, 99, 0, 29, 45, 16, 36, 29, 78, 75, 12, 60, 70, 63, 13, 95, 32, 56, 13, 51, 5, 99};

void search(int* birth, int y);
int count_10_birth(int * birth, int y);
int sum_50y(int *birth, int y, int y_1985, int y_o);
int main(){
    printf("\n");
    search(birth,51);
    printf("So nam co ca sinh khong qua 10: %d\n", count_10_birth(birth, 51));
    printf("Tai nam 1985, nhung nguoi da tren 50 tuoi la: %d\n ", sum_50y(birth,51,1985, 50));
}

void search (int* birth, int y){
    for(int i = 0; i < (y_1970 + 1);i++){
        if(!birth[i]) {
            printf ("%d ", i + 1920);
        }
    }
    printf("\n");
}
int count_10_birth(int * birth, int y){
    int count = 0;
    for(int i = 0; i < (y_1970 + 1);i++){
        if(birth[i] <= 10){
            count++;
        }
    }
    return count;
}

int sum_50y(int *birth, int y, int y_1985, int y_o){
    int sum = 0; 
    for(int i = 0; i < (y_1920 + (y_1985-y_o - 1920+1)); i++){
        sum += birth[i];
    }
    return sum;
}