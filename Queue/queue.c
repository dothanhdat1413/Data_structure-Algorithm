#include "queue.h"

const data_type data[3] = {
    {.name = "User_1", .items = {.name = "Fruit", .price = 10, .quantity = 10}, .time = {.hour = 12, .minute = 30, .second = 0, .day = 1, .month = 1, .year = 2021}},
    {.name = "User_2", .items = {.name = "Snack", .price = 10, .quantity = 10}, .time = {.hour = 12, .minute = 31, .second = 0, .day = 1, .month = 1, .year = 2021}},
    {.name = "User_3", .items = {.name = "Rice", .price = 10, .quantity = 10}, .time = {.hour = 12, .minute = 32, .second = 0, .day = 1, .month = 1, .year = 2021}}
};



Queue Q;

int main(){
    Queue_init(&Q);
    for(int i = 0; i < 3; i++){
        printf("Add user %d\n", i+1);
        Queue_insert(&Q, data[i]);
    }
    printf("Current queue: \n");
    printf("______________________________________\n");
    Queue_print(&Q);
    printf("______________________________________\n");

    int revenue = 0;
    while(Queue_is_empty(&Q) == 0){
        data_type data_get;
        Queue_get(&Q, &data_get);
        revenue += data_get.items.price * data_get.items.quantity;
        printf("Bill of %s done\n", data_get.name);
        // printf("Current queue: \n");
        // printf("______________________________________\n");
        // Queue_print(&Q);
        // printf("______________________________________\n");
    }

    printf("Revenue: %d\n", revenue);
}