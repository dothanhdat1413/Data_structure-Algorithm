#ifndef __STACK_STATIC_H__
#define __STACK_STATIC_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Kích thước tối đa của stack

enum WOOD_TYPE {
    GU,
    LIM,
    SEN,
    SOI,
    OC_CHO
};

/**
 * @brief Thông tin gỗ
 * @param id: loại gỗ
 * @param size: kích thước
 * @param age: tuổi
 */
typedef struct {
    unsigned int id; // loại gỗ
    unsigned int size; 
    unsigned int age;
} data_type;

/**
 * @brief Stack
 * @param data: mảng chứa dữ liệu
 * @param top: stack pointer
 */
typedef struct {
    data_type data[MAX];
    int top;
} Stack;

/**
 * @brief Khởi tạo stack, đặt top về -1
 * 
 * @param s stack cần khởi tạo
 */
void Stack_init(Stack *s) {
    s->top = -1;
}

/**
 * @brief Kiểm tra stack rỗng
 * 
 * @param s 
 * @return 1 nếu stack rỗng, ngược lại trả về 0
 */
int Stack_isEmpty(Stack *s) {
    return (s->top == -1);
}

/**
 * @brief Kiểm tra stack đầy
 * 
 * @param s 
 * @return 1 nếu stack đầy, ngược lại trả về 0
 */
int Stack_isFull(Stack *s) {
    return (s->top == MAX - 1);
}

/**
 * @brief Thêm phần tử vào stack
 * 
 * @param s 
 * @param new_data 
 * @return 1 nếu thêm thành công, ngược lại trả về 0
 */
int Stack_push(Stack *s, data_type new_data) {
    if (Stack_isFull(s)) {
        printf("Full!\n");
        return 0;
    }
    s->data[++s->top] = new_data;
    return 1;
}

/**
 * @brief Lấy phần tử ra khỏi stack
 * 
 * @param s stack lưu dữ liệu
 * @param pop_data : nơi lưu dữ liệu được lấy ra
 * @return 1 nếu lấy thành công, ngược lại trả về 0 
 */
int Stack_pop(Stack *s, data_type *pop_data) {
    if (Stack_isEmpty(s)) {
        printf("Stack rỗng!\n");
        return 0;
    }
    *pop_data = s->data[s->top--];
    return 1;
}

/**
 * @brief Lấy dữ liệu của phần tử đầu stack (ko xóa phần tử đó)
 * 
 * @param s 
 * @param top_data 
 * @return 1 nếu lấy thành công, ngược lại trả về 0
 */
int Stack_getTop(Stack *s, data_type *top_data) {
    if (Stack_isEmpty(s)) {
        printf("Stack rỗng!\n");
        return 0;
    }
    *top_data = s->data[s->top];
    return 1;
}

/**
 * @brief In ra toàn bộ dữ liệu trong stack và coi như xóa stack
 * 
 * @param s 
 * @return 1 nếu in thành công, ngược lại trả về 0
 */
int Stack_printf(Stack *s) {
    if (Stack_isEmpty(s)) {
        printf("Empty!\n");
        return 0;
    }
    int count = s->top;
    while(count >= 0) {
        data_type temp;
        temp = s->data[count];

        printf("\t");
        switch (temp.id){
        case GU:
            printf("Gu");
            break;
        case LIM:
            printf("Lim");
            break;
        case SEN:
            printf("Sen");
            break;
        case SOI:
            printf("Soi");
            break;
        case OC_CHO:
            printf("Oc cho");
            break;
        default:
            break;
        }
        printf(", size: %d, age: %d\n", temp.id, temp.size, temp.age);
        count--;
    }
    return 1;
}

int Stack_push_any(Stack *s, data_type new_data, int k) {
    if(Stack_isFull(s)) {
        printf("Full!\n");
        return 0;
    }
    int temp_count = s->top + 1 - k;
    if(temp_count < 0) {
        temp_count = 0;
        Stack_push(s, new_data);
    } else {
        if(temp_count > (s->top + 1)) {
            temp_count = s->top + 1;
        }
        
        data_type* temp = (data_type*) malloc(sizeof(data_type)*temp_count);
        for(int i = temp_count - 1 ; i >= 0; i--) {
            Stack_pop(s, &temp[i]);
        }
        Stack_push(s, new_data);

        for(int i = 0; i < temp_count; i++) {
            Stack_push(s, temp[i]);
        }
        free(temp);
    }

    return 1;
}

#endif