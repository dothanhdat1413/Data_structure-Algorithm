#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef int data_type;
typedef struct time_in {
    char hour;
    char minute;
    char day;
    char month;
    short int year; 
} time_in;

typedef struct {
    char name[100];
    unsigned long size;
    time_in time;
} data_type;


typedef struct Node
{   
    data_type data;
    struct Node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
} List;

/**
 * @brief Hàm khởi tạo list với 2 node đầu và cuối
 * 
 * @param L danh sách cần khởi tạo
 * @param first Node đầu
 * @param last Node cuối
 */
void List_init(List *L, Node* first, Node* last);

#define FIRST 1
#define NOT_FIRST 0
#define LAST 1
#define NOT_LAST 0
#define NONE -1
/**
 * @brief Hàm thêm 1 node vào list vào vị trí đầu/cuối/index
 * 
 * @param L 
 * @param node 
 * @param index vị trí muốn add vào, nếu index vượt quá thì thêm vào vị trí cuối, index tính từ 1
 * @param add_first 
 * @param add_last 
 */
void List_add(List *L, Node* node, int index, int add_first, int add_last);
/**
 * @brief Xóa node đầu/ cuối/ vị trí thứ i khỏi list
 * 
 * @param L 
 * @param index tính từ 0
 * @param remove_first 
 * @param remove_last 
 */
void List_remove(List *L, int index, int remove_first, int remove_last );

#define SIZE 0
#define TIME 1
/**
 * @brief So sánh 2 node
 * 
 * @param A 
 * @param B 
 * @param mode SIZE: so sánh theo size, TIME: so sánh theo thời gian 
 * @return int 1 nếu A > B về size hoặc mới hơn, 0 nếu A <= B
 */
int Node_compare(Node* A, Node* B, int mode);

/**
 * @brief Khởi tạo 1 node với data cho sẵn
 * 
 * @param N 
 * @param data 
 * @return Node* 
 */
Node* Node_init(Node* N, data_type data);

/**
 * @brief Đổi vị trí 2 Node, để đỡ phải tính nhiều link thì thôi cứ để yên link, đổi data :))
 * 
 * @param A 
 * @param B 
 */
void Node_swap(Node* A, Node* B);
/**
 * @brief Sắp xếp danh sách theo size hoặc thời gian
 * 
 * @param L 
 * @param mode 
 */
void List_sort(List *L, int mode);

/*
 * @brief Giải phóng toàn bộ danh sách
 * 
 * @param L 
 */
void List_delete(List *L);

/**
 * @brief Xóa node có data = condition
 * 
 * @param L 
 * @param condition 
 */
void List_remove_condition(List *L, data_type condition);

void List_print(List *L);

/**
 * @brief Hàm di chuyển con trở đến vị trí node thứ index của list tính từ 0
 * 
 * @param L 
 * @param index tính từ 0
 * @param condition giá trị của Node cần tìm
 * @return Node* 
 */
Node* List_goto(List *L, int index);

void List_init(List *L, Node* first, Node* last)
{   
    L->first = first;
    L->first->next = last;
    L->last = last;
}

void List_add(List *L, Node *new_node, int index, int add_first, int add_last)
{       
    if(add_first || index == 1)
    {
        new_node->next = L->first;
        L->first = new_node;
        return;
    }

    if(add_last)
    {
        L->last->next = new_node;
        L->last = new_node;
        return;
    }

    Node* p = List_goto(L, index - 1 -1); // đến vị trí trước vị trí cần add
    if(p != NULL)
    {
        new_node->next = p->next;
        p->next = new_node;
        return;
    }

    // Khi duyệt hết rồi mà vẫn thấy index thì thêm vào cuối
    new_node->next = NULL;
    L->last->next = new_node;
    L->last = new_node;
    return;
}

void List_remove(List *L, int index, int remove_first, int remove_last)
{
    if(remove_first || index == 0)
    {   
        Node* temp = L->first->next;
        free(L->first);
        L->first = temp;

        return;
    }

    if(remove_last)
    {
        Node* p = L->first;
        while(p->next->next != NULL) // Duyệt tới vị trí trước cuối cùng
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
        L->last = p;
        return;
    }

    Node* p = List_goto(L, index - 1); // Tới vị trí trước vị trí cần xóa
    if(p != NULL){
        Node* temp = p->next->next; // Phần tử sau phần tử cần xóa

        if(temp == NULL) {
            L->last = p; // Nếu xóa phần tử cuối thì cập nhật lại last
        }

        free(p->next);
        p->next = temp;
        return;
    } // Không có vị trí đó trong danh sách, index nhập vào tính từ 1

    // Khi duyệt hết rồi mà vẫn thấy chưa thấy index thì xóa node cuối
    while(p->next->next != NULL) // Duyệt tới vị trí trước cuối cùng
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    L->last = p;
    return;
}   

void List_delete(List *L)
{
    Node* p = L->first;
    int i = 0;
    while(p->next != NULL)
    {
        Node* temp = p->next;
        free(p);
        p = temp;
        printf("List delete %d\n", i);
        i++;
    }
    free(p);
    printf("List deleted\n");
}

Node* List_goto(List *L, int index){
    Node* p = L->first;
    int i = 0;
    while(p->next != NULL)
    {
        if(i == index)
        {   
            return p;
            break;
        }

        i++;
        p = p->next;
    }
    return NULL; // Không có vị trí đó trong danh sách, index nhập vào tính từ 0
}


int Node_compare(Node *A, Node *B, int mode)
{
    switch (mode)
    {
    case SIZE:
        if(A->data.size > B->data.size)
            return 1;
        break;
    
    case TIME:
        if(A->data.time.year > B->data.time.year){ // mới hơn
            return 1;
        } else if(A->data.time.month > B->data.time.month){ // mới hơn
            return 1;
        } else if(A->data.time.day > B->data.time.day){ // mới hơn
            return 1;
        } else if(A->data.time.hour > B->data.time.hour){ // mới hơn
            return 1;
        } else if(A->data.time.minute > B->data.time.minute){ // mới hơn
            return 1;
        }
        break;
    default:
        break;
    }

    return 0;
}

void Node_swap(Node* A, Node* B)
{
    data_type temp = A->data;
    A->data = B->data;
    B->data = temp;
}

void List_sort(List *L, int mode){
    Node* p = L->first;
    int first = 0;
    int n = 0; 
    int i = -10;
    int j = 0;
    // bubble sort cần xác định được tổng số phần tử và cần có 2 biến i, j để duyệt
    // do đó lần đầu tiên bubble thì sẽ tính tổng số phần tử
    while(n != i){ // Số lần duyệt bằng số phần tử của list - 1 (n = N - 1)
        while((p->next != NULL) && (j != (n - i))){ // Đẩy dần phần tử lớn hơn lên trên
            if(Node_compare(p,p->next,mode)){
                Node_swap(p,p->next);
            }
            if(first == 0){
                n++; // = n - 1
            }
            p = p->next; // đến phần tử tiếp theo
            j++;
        }
        if(first == 0){
            i = 0;
            first = 1;
        }
        p = L->first; // quay lại đầu danh sách
        i++;
        j = 0;
    }
}

Node* Node_init(Node* N, data_type data){
    N->data = data;
    return N;
}

void List_remove_condition(List *L, data_type condition)
{
    Node* p = L->first;
    int i = 0;
    printf("Start check remove\n");
    do
    {
        if((strcmp(p->data.name, condition.name) == 0) && (p->data.size == condition.size) && (p->data.time.hour == condition.time.hour) && (p->data.time.minute == condition.time.minute) && (p->data.time.day == condition.time.day) && (p->data.time.month == condition.time.month) && (p->data.time.year == condition.time.year)) {
            printf("Remove %d\n", i);
            List_remove(L, i, 0, 0);
            return;
        } else {
            p = p->next; 
            i++;
        }
    }
    while(p != NULL);

}

// /*
void List_print(List *L){
    Node* p = L->first;
    int i = 0;
    while(p != NULL){
        printf("File name: %s \n", p->data.name);
        printf("\t  File size: %lu \n", p->data.size);
        printf("\t  File time: %d:%d %d/%d/%d \n",p->data.time.hour, p->data.time.minute, p->data.time.day, p->data.time.month, p->data.time.year);
        p = p->next;
    }
    printf("\n");
}
// */


#endif