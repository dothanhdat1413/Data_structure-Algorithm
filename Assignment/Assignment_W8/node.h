#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef int data_type;

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
 * @param index tính từ 1
 * @param remove_first 
 * @param remove_last 
 */
void List_remove(List *L, int index, int remove_first, int remove_last );
/**
 * @brief Giải phóng toàn bộ danh sách
 * 
 * @param L 
 */
void List_delete(List *L);

/**
 * @brief Hàm di chuyển con trở đến vị trí node thứ index của list tính từ 0
 * 
 * @param L 
 * @param index tính từ 0
 * @return Node* 
 */
Node* List_goto(List *L, int index);

void List_init(List *L, Node* first, Node* last)
{   
    printf("List init\n");
    L->first = first;
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
    if(remove_first || index == 1)
    {   
        Node* temp = L->first;
        free(L->first);
        L->first = L->first->next;
        printf("List remove first");
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
        printf("List remove last");
        return;
    }

    Node* p = List_goto(L, index - 1 - 1); // Tới vị trí trước vị trí cần xóa
    if(p == NULL){
        Node* temp = p->next->next;
        free(p->next);
        p->next = temp;
        printf("List remove %d\n", index);
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
    printf("List remove last");
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
        printf("%d\n", i);
        if(i == index)
        {   
            printf("FOUND");
            return p;
            printf("CANT NOT RETURN");
            break;
        }

        i++;
        p = p->next;
    }
    return NULL; // Không có vị trí đó trong danh sách, index nhập vào tính từ 0
}
#endif