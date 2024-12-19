#include <stdio.h>
#include <stdlib.h>

// #define TEST 1
typedef struct NODE {
    int a;
    unsigned short int ex;
    NODE* next;
} NODE;

typedef struct {
    NODE* head;
    NODE* tail;
}EQUATION;

void EQUATION_pushback(int a, unsigned short int ex, EQUATION* equation){
    NODE* p = (NODE*)malloc(sizeof(NODE));
    p->a = a;
    p->ex = ex;
    p->next = NULL;
    if(equation->head == NULL){
        equation->head = p;
#ifdef TEST
        printf("HEAD\n");    
#endif
    }else if(equation->tail == NULL){
        equation->head->next = p;
        equation->tail = p;
#ifdef TEST
        printf("TAIL\n");  
        if(p->next == NULL) printf("NULL\n"); 
#endif
    } else {
        equation->tail->next = p; // Trỏ node cuối vào node mới
        equation->tail = p; // Đặt node mới thành node cuối mới của danh sách
#ifdef TEST
        printf("ANY\n");    
#endif
    }
    
#ifdef TEST
    printf("Added\n");    
#endif
}

void EQUATION_input(EQUATION* equation){
    int ex_temp = 0;
    int a_temp = 0;
    char want_input = 'y';
    while (((want_input != 'N')&&(want_input != 'n'))){
        printf("\nNhap so mu: ");
        fflush(stdin);
        scanf("%d", &ex_temp);
        printf("Nhap he so: ");
        fflush(stdin);
        scanf("%d", &a_temp);

        if(a_temp != 0){
            NODE* p = equation->head;
            if(p != NULL){
                while(p->ex != ex_temp){
                    if(p->next == NULL){
                        break;
                    }
                    p = p->next; // Duyệt tới vị trí có số mũ bằng số mũ nhập vào nếu có
                }
                if(p->ex == ex_temp){ // Nếu số mũ đó đã có rồi thì chỉ cần cộng thêm vào nữa thôi
                    p->a += a_temp;
                } else {
                    EQUATION_pushback(a_temp, ex_temp, equation);
                }
            } else {
                EQUATION_pushback(a_temp, ex_temp, equation);
            }   
        }
        printf("Ban co muon nhap tiep hay khong (y/n)? ");
        fflush(stdin);
        scanf("%c", &want_input);
    }
};

void NODE_swap(NODE* A, NODE* B){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->a = A->a;
    temp->ex = A->ex;
    temp->next = A->next;

    A->a = B->a;
    A->ex = B->ex;

    B->a = temp->a;
    B->ex = temp->ex;

#ifdef TEST
    if(A->next == NULL) printf("NULL_A\n");
    if(B->next == NULL) printf("NULL_B\n");
#endif
    free(temp);
}

int NODE_compare(NODE* A, NODE* B){
    if(A->ex < B->ex){
#ifdef TEST
        printf("COMPARED\n");
#endif
        return 1;
    }
#ifdef TEST
    printf("Compared\n");
#endif
    return 0;
}
void EQUATION_sort(EQUATION* equation){
    NODE* p = equation->head;
    NODE* cur = equation->head;
    while(cur->next != NULL){
        while(p->next != NULL){
            if(NODE_compare(p,p->next)){
                NODE_swap(p,p->next);
            }
            p = p->next; // đến phần tử tiếp theo
#ifdef TEST
    printf("BUBBLE\n");
    if(p->next == NULL) printf("NULL\n");
#endif
        }
        cur = cur->next;
    }
#ifdef TEST
    printf("Sorted\n");
#endif
}

void EQUATION_output(EQUATION* equation){
    NODE* p = equation->head;
    while(p->next != NULL){
        printf("%dx^%d + ", p->a, p->ex);
        p = p->next;
    } 
    printf("%dx^%d", p->a, p->ex);
}

void EQUATION_delete(EQUATION* equation){
    NODE* p = equation->head;
    while(p != NULL){
        NODE* temp = p;
        p = p->next;
        free(temp);
    }
}
int main(){  
    NODE* head = NULL;
    NODE* tail = NULL;

    EQUATION equation = {head, tail};

    printf("Nhap da thuc f(x):");
    EQUATION_input(&equation);
    printf("\nNhap da thuc g(x):"); 
    EQUATION_input(&equation);

    EQUATION_sort(&equation);
    EQUATION_output(&equation);
    EQUATION_delete(&equation);
    return 0;
}