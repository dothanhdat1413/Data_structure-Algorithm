#include <stdio.h>
#include <stdlib.h>
#include "./Node.h"
/*  Nhận thấy giống như việc xoay vòng 1 danh sách và gạch dần 
    -> Sử dụng 1 danh sách có đàu và đuôi nối vào nhau
    */
#define TEST 1
int Game_init(List* L, int N);
int Game_play(List* L, int M);

int M = 0;
int N = 5;

int main() {
    List* L;
    if(Game_init(L, N) == 0){
        printf("Error\n");
        return 0;
    }

    Node* p = L->first;
    int i = 0;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("Winner: %d\n", Game_play(L,M));

    List_delete(L);
    return 0;
}

int Game_init(List* L, int N)
{
    if(N < 2) return 0; // Phải có 2 người trở lên

    Node* first = (Node*)malloc(sizeof(Node));
    Node* last = (Node*)malloc(sizeof(Node));
    first -> data = 1;
    first -> next = last; 
    last -> data = N;
    last -> next = NULL;
    List_init(L,first,last);

    for(int i = 2; i < N; i++){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = i;
        List_add(L,new_node,i,0,0);
    }

#ifdef TEST
    printf("INIT\n");
#endif
    return 1;
}

int Game_play(List* L, int M)
{   
    Node* p = L->first;
    Node* temp = NULL;
    while(L->first->next != NULL){ // khi mà danh sách vẫn còn 2 người trở lên
        for(int i = 0; i < M; i++){
            if(p->next == NULL) {
                p = L->first;
                continue;
            }
            p = p->next;
        } // duyệt tới vị trí thứ M
        printf("Player %d is out\n", p->data);
        temp = p->next;
        
        free(p);
        p = temp; // đây mới chỉ là xóa khỏi danh sách và duyệt tới phần tử kế tiếp thôi
    }

    return L->first->data;
}
