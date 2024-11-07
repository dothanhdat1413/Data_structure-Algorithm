#include <stdio.h>
#include <stdlib.h>


typedef  struct { 
    int ngay, thang, nam; 
} Ngay; 
typedef struct { 
    char maSV[8]; 
    char hoTen[50]; 
    int gioiTinh; 
    Ngay ngaySinh; 
    char diaChi[100]; 
    char lop[12]; 
    char khoa[7]; 
} SinhVien;

typedef struct Node{ 
    SinhVien data; 
    Node *next; 
} Node;

typedef struct { 
    Node *first;
    Node *last;
} List;

/**
 * @brief Nhập lần đầu
 * 
 * @param L 
 */
void input(List* L);
/**
 * @brief In tất cả ra danh sách
 * 
 * @param L 
 */
void output(List* L);

/**
 * @brief So sánh mã số sinh viên của 2 Node
 * 
 * @param A địa chỉ node A 
 * @param B địa chỉ node B
 * @return 1 nếu MSSV của A > B, 0 là còn lại
 */
int compare(Node* A, Node* B);
/**
 * @brief Đổi chỗ 2 thằng
 * 
 * @param a
 * @param b
 */
void swap(Node* a, Node* b);
/**
 * @brief sort danh sách theo thứ tự tăng dần theo mã sinh viên, sử dụng bubble sort
 * 
 * @param L 
 */
void sort(List* L);
/**
 * @brief thêm hồ sơ sinh viên vào
 * 
 * @param L list sinh viên 
 * @param N
 */
void insert(List*L, Node*N);

int main() {
    Node f_node;
    Node l_node;
    List L;
    L.first = &f_node;
    L.last = &l_node;
    input(&L);
    output(&L);
    return 0;
}

void input(List*L){
    int i = 0;
    printf("Nhap sinh vien thu %d:\n", i);
    printf("    Nhap ma sinh vien: ");
    fflush(stdin);
    gets(L->first->data.maSV);
    printf("    Nhap ho ten sinh vien: ");
    fflush(stdin);
    gets(L->first->data.hoTen);
    printf("    Nhap ngay sinh: ");
    fflush(stdin);
    scanf("%d", &L->first->data.ngaySinh.ngay);
    printf("    Nhap thang sinh: ");
    fflush(stdin);
    scanf("%d", &L->first->data.ngaySinh.thang);
    printf("    Nhap nam sinh: ");
    fflush(stdin);
    scanf("%d", &L->first->data.ngaySinh.nam);
    printf("    Nhap dia chi: ");
    fflush(stdin);
    gets(L->first->data.diaChi);
    printf("    Nhap lop: ");
    fflush(stdin);
    gets(L->first->data.lop);
    printf("    Nhap khoa: ");
    fflush(stdin);
    gets(L->first->data.khoa);
    L->first->next = L->last;
    i++;

    printf("Nhap sinh vien thu %d:\n", i);
    printf("    Nhap ma sinh vien: ");
    fflush(stdin);
    gets(L->last->data.maSV);
    printf("    Nhap ho ten sinh vien: ");
    fflush(stdin);
    gets(L->last->data.hoTen);
    printf("    Nhap ngay sinh: ");
    fflush(stdin);
    scanf("%d", &L->last->data.ngaySinh.ngay);
    printf("    Nhap thang sinh: ");
    fflush(stdin);
    scanf("%d", &L->last->data.ngaySinh.thang);
    printf("    Nhap nam sinh: ");
    fflush(stdin);
    scanf("%d", &L->last->data.ngaySinh.nam);
    printf("    Nhap dia chi: ");
    fflush(stdin);
    gets(L->last->data.diaChi);
    printf("    Nhap lop: ");
    fflush(stdin);
    gets(L->last->data.lop);
    printf("    Nhap khoa: ");
    fflush(stdin);
    gets(L->last->data.khoa);
    L->last->next = NULL;
    i++;

    char want_input='Y';
    printf("Ban co muon nhap tiep khong (Y/N)?");
    fflush(stdin);
    scanf("%c", &want_input);
    printf("%c\n", want_input);

    while(((want_input != 'N')&&(want_input != 'n'))) {   
        L->last->next = (Node*)malloc(sizeof(Node)); // gán next của cuối mới vào next của cuối cũ
        L->last = L->last->next;// cập nhật last mới của list 
        printf("Nhap sinh vien thu %d:\n", i);
        printf("    Nhap ma sinh vien: ");
        fflush(stdin);
        gets(L->last->data.maSV);
        printf("    Nhap ho ten sinh vien: ");
        fflush(stdin);
        gets(L->last->data.hoTen);
        printf("    Nhap ngay sinh: ");
        fflush(stdin);
        scanf("%d", &L->last->data.ngaySinh.ngay);
        printf("    Nhap thang sinh: ");
        fflush(stdin);
        scanf("%d", &L->last->data.ngaySinh.thang);
        printf("    Nhap nam sinh: ");
        fflush(stdin);
        scanf("%d", &L->last->data.ngaySinh.nam);
        printf("    Nhap dia chi: ");
        fflush(stdin);
        gets(L->last->data.diaChi);
        printf("    Nhap lop: ");
        fflush(stdin);
        gets(L->last->data.lop);
        printf("    Nhap khoa: ");
        fflush(stdin);
        gets(L->last->data.khoa);
        L->last->next = NULL;
        i++;

        printf("Ban co muon nhap tiep khong (Y/N)?");
        fflush(stdin);
        scanf("%c", &want_input);
    }
}

void output(List *L){
    Node *p = L->first;
    int i = 0;
    while(p != NULL){
        printf("Sinh vien thu %d:\n", i);
        printf("    Ma sinh vien: %s\n", p->data.maSV);
        printf("    Ho ten sinh vien: %s\n", p->data.hoTen);
        printf("    Ngay sinh: %d/%d/%d\n", p->data.ngaySinh.ngay, p->data.ngaySinh.thang, p->data.ngaySinh.nam);
        printf("    Dia chi: %s\n", p->data.diaChi);
        printf("    Lop: %s\n", p->data.lop);
        printf("    Khoa: %s\n", p->data.khoa);
        p = p->next;
        i++;
    }
}

int compare(Node* A, Node* B){
    for(int i = 7; i>=0 ;i--){
        if(A->data.maSV[i] > B->data.maSV[i]){
            return 1;
        }
    }
    return 0;
}

void swap(Node* A, Node* B){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = A->data;
    A->data = B->data;
    B->data = temp->data;
    free(temp);
}
void sort(List* L){
    Node* p = L->first;
    Node* cur = L->first;
    while(cur->next != NULL){
        while(p->next != NULL){
            if(compare(p,p->next)){
                swap(p,p->next);
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

void insert(List* L, Node* N){
    Node* p = L->first;
    while(!compare(N->data.maSV,p->data.maSV)){
        p = p -> next;
    }
    N->next = p->next;
    p->next->next = N;
}
