#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM 1
#define MAX_QUEUE 10
#define MAX_NAME 10

typedef struct {
    char hour;
    char minute;
    char second;
    char day;
    char month;
    short int year;
} time_type;

/**
 * @brief item struct
 * @param name
 * @param price
 * @param quantity
 */
typedef struct{
    char name[MAX_NAME];
    unsigned int price;
    unsigned int quantity;
} item;

/**
 * @brief user_bill
 * @param name
 * @param items
 * @param time
 */
typedef struct{
    char name[MAX_NAME];
    item items;
    time_type time;
} data_type;

/**
 * @brief Queue struct
 * @param data
 * @param front
 * @param rear
 */
typedef struct{
    data_type data[MAX_QUEUE];
    unsigned int front;
    unsigned int rear;
} Queue;

void Queue_init(Queue* Q){
    Q->front = 0;
    Q->rear = 0;
}
int Queue_is_empty(Queue* Q){
    return Q->front == Q->rear; // đầu cuối trùng nhau
}
int Queue_is_full(Queue* Q){
    return Q->rear == (MAX_QUEUE); // 
}
int Queue_insert(Queue* Q, data_type data){
    if(Queue_is_full(Q)){
        printf("Queue is full\n");
        return 0;
    }
    Q->data[Q->rear] = data;
    Q->rear++;
    return 1;
}
int Queue_get(Queue* Q, data_type* data_get){
    if(Queue_is_empty(Q)){
        printf("Queue is empty\n");
        return 0;
    }
    *data_get = Q->data[Q->front];
    Q->front++;
    return 1;
}

int Queue_print(Queue* Q){
    if(Queue_is_empty(Q)){
        printf("Queue is empty\n");
        return 0;
    }
    for(int i = Q->front; i < Q->rear; i++){
        printf("%d:%d %d/%d/%d\t", Q->data[i].time.hour, Q->data[i].time.minute, Q->data[i].time.day, Q->data[i].time.month, Q->data[i].time.year);
        printf("%s \n", Q->data[i].name);
        printf("\t %s\n", Q->data[i].items.name);
        printf("\t Price: %d\n", Q->data[i].items.price);
        printf("\t Quantity: %d\n", Q->data[i].items.quantity);
    }
    return 1;
}

void Queue_delete(Queue* Q){
    Q->front = 0;
    Q->rear = 0;
};


#endif // __QUEUE__H__