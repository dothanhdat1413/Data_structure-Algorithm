#include "Node_file.h"

#define MAX_32G 150
List L_1;
List L_2;

void File_cut_to_fit(List *L);

data_type DATA [10] = {
    {"Nhac tieng Anh vui"   , 110   , { 5, 31, 1, 1, 2019} },
    {"Nhac tieng Anh buon"  , 120   , { 6, 30, 1, 1, 2021} },
    {"Nhac tieng Nhat vui"  , 130   , { 7, 29, 1, 1, 2030} },
    {"Nhac tieng Nhat buon" , 140   , { 8, 28, 1, 1, 2022} },
    {"Nhac tieng Viet vui"  , 90    , { 9, 27, 1, 1, 2021} },
    {"Nhac tieng Viet buon" , 80    , {10, 26, 1, 1, 2008} },
    {"Nhac tieng Trung vui" , 100   , {11, 25, 1, 1, 2009} },
    {"Nhac tieng Trung buon", 50    , {12, 24, 1, 1, 2003} },
    {"Nhac khong loi vui"   , 150   , {13, 23, 1, 1, 2001} },
    {"Nhac khong loi buon"  , 160   , {15, 22, 1, 1, 2011} }
};


int main(){
// Khởi tạo Folder L1
    Node* first_1 = (Node*)malloc(sizeof(Node));
    Node* last_1 = (Node*)malloc(sizeof(Node));
    Node_init(first_1, DATA[0]);
    Node_init(last_1, DATA[9]);

    List_init(&L_1, first_1, last_1);

// Thêm file vào Folder L1
    Node* file_1_0 = (Node*)malloc(sizeof(Node));
    Node_init(file_1_0, DATA[1]);
    List_add(&L_1, file_1_0, NONE, NOT_FIRST, LAST); 

    Node* file_1_1 = (Node*)malloc(sizeof(Node));
    Node_init(file_1_1, DATA[3]);
    List_add(&L_1, file_1_1, NONE, NOT_FIRST, LAST); 

    Node* file_1_2 = (Node*)malloc(sizeof(Node));
    Node_init(file_1_2, DATA[4]);
    List_add(&L_1, file_1_2, NONE, NOT_FIRST, LAST); 

// Khởi tạo Folder L2  
    Node* first_2 = (Node*)malloc(sizeof(Node));
    Node* last_2 = (Node*)malloc(sizeof(Node));
    Node_init(first_2, DATA[5]);
    Node_init(last_2, DATA[7]);
    List_init(&L_2, first_2, last_2);

// Thêm file vào Folder L2
    Node* file_2_0 = (Node*)malloc(sizeof(Node));
    Node_init(file_2_0, DATA[2]);
    List_add(&L_2, file_2_0, NONE, NOT_FIRST, LAST);

// Sắp xếp list 1 tăng dần theo size
    List_sort(&L_1, SIZE); // PASS
    // printf("Sap xep theo size: \n");
    // List_print(&L_1);

// Xóa phần tử theo điều kiện
    Node* p = List_goto(&L_1, 2); 
    List_remove_condition(&L_1, p->data); // PASS
    // printf("Xoa phan tu theo dieu kien");
    // List_print(&L_1);
// Xóa phần tử đầu
    List_remove(&L_1, NONE, FIRST, NOT_LAST); // PASS
    // printf("Xoa phan tu dau");
    // List_print(&L_1);
// Xóa phần tử cuối
    List_remove(&L_1, NONE, NOT_FIRST, LAST); // PASS
    // printf("Xoa phan tu cuoi");
    // List_print(&L_1);
// Xóa file để vừa với dung lượng theo size
    File_cut_to_fit(&L_1); // PASS
    // printf("Xoa file de vua voi dung luong theo size");
    // List_print(&L_1);
// Giải phóng
    List_delete(&L_1);
    List_delete(&L_2);
}


void File_cut_to_fit(List* L){
    Node* p = L->first;
    unsigned long long file_size = 0;
    List_sort(L, SIZE);
    while(p != NULL){
        file_size += p->data.size;
        p = p->next;    
    }

    while(file_size > MAX_32G){
        file_size -= L->first->data.size;
        List_remove(L, NONE, FIRST, NOT_LAST);
    }
}