#include "Node_file.h"

#define MAX_32G 1000
List L_1;
List L_2;

void add_file_to_List(List *L, Node* file);
void cut_file_to_fit(List *L);

int main(){
    Node* first_1 = (Node*)malloc(sizeof(Node));
    strcpy(first_1->data.name, "Nhac_vui_vui");
    first_1->data.size = 100;
    first_1->data.time.hour = 12;
    first_1->data.time.minute = 31;
    first_1->data.time.day = 1;
    first_1->data.time.month = 1;
    first_1->data.time.year = 2021;

    Node* last_1 = (Node*)malloc(sizeof(Node));
    strcpy(last_1->data.name, "Nhac_buon_buon");
    last_1->data.size = 100;
    last_1->data.time.hour = 12;
    last_1->data.time.minute = 30;
    last_1->data.time.day = 1;
    last_1->data.time.month = 1;
    last_1->data.time.year = 2021;

    List_init(&L_1, first_1, last_1);
    
    Node* first_2 = (Node*)malloc(sizeof(Node));
    strcpy(first_2->data.name, "Nhac_vui");
    first_2->data.size = 100;
    first_2->data.time.hour = 12;
    first_2->data.time.minute = 41;
    first_2->data.time.day = 1;
    first_2->data.time.month = 1;
    first_2->data.time.year = 2021;

    Node* last_2 = (Node*)malloc(sizeof(Node));
    strcpy(last_2->data.name, "Nhac_buon");
    last_2->data.size = 100;
    last_2->data.time.hour = 12;
    last_2->data.time.minute = 40;
    last_2->data.time.day = 1;
    last_2->data.time.month = 1;
    last_2->data.time.year = 2021;

    List_init(&L_2, first_2, last_2);

    Node* file_2_0 = (Node*)malloc(sizeof(Node));
    strcpy(file_2_0->data.name, "Nhac_vua_vua");
    file_2_0->data.size = 100;
    file_2_0->data.time.hour = 12;
    file_2_0->data.time.minute = 41;
    file_2_0->data.time.day = 1;
    file_2_0->data.time.month = 1;
    file_2_0->data.time.year = 2021;

    List_add(&L_2, file_2_0, 1, 1, 0); // file này thuộc file L2

    add_file_to_List(&L_1, file_2_0);

    List_delete(&L_1);
    List_delete(&L_2);
}

void add_file_to_List(List *L, Node* file){
    Node* p = L->first;
    while(p->next != NULL)
    {
        if(Node_compare(p, file, TIME)) // mới hơn thì chèn vào ngay sau
        {
            Node* temp = p->next;
            p->next = file;
            file->next = temp;
            return;
        }
        p = p->next;
    }
    List_add(L, file, 0, 0, 1);
    return;
}

void cut_file_to_fit(List *L){
    Node* p = L->first;
    unsigned long long total_size = 0;
    
    while(p->next->next != NULL)    // duyệt đến node trước node cuối
    {

    }

}

void cut_file_to_fit(List* L) {
    if (!L || !L->first) return;

    unsigned long long total_size = 0;
    int swapped;

    // Sắp xếp các file lớn lên đầu và dừng sớm khi đạt MAX_32G
    do {
        swapped = 0;
        Node* current = L->first;
        Node* prev = NULL;

        while (current->next != NULL) {
            if (Node_compare(current, current->next, SIZE)) {
                Node_swap(current, current->next);
                swapped = 1;
            }

            if (prev == NULL) {  
                total_size += current->data.size;
                if (total_size > MAX_32G) {
                    L->last = prev; 
                    prev->next = NULL;

                    // Dừng sớm và giải phóng
                    Node* to_free = current->next;
                    while (to_free) {
                        Node* temp = to_free;
                        to_free = to_free->next;
                        free(temp);
                    }
                    return;
                }
            }

            prev = current;
            current = current->next;
        }
    } while (swapped);
}