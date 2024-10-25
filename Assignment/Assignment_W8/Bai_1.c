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
    Node *link; 
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
 * @brief So sánh 2 chuỗi số dưới dạng char
 * 
 * @param a 
 * @param b 
 * @return 1 nếu a>b, 0 nếu a=b, -1 nếu a<b
 */
int compare(char[8] a, char[8]b);
/**
 * @brief sort danh sách theo thứ tự tăng dần theo mã sinh viên
 * 
 * @param L 
 */
void sort(List* L);

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
    L->first->link = L->last;
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
    L->last->link = NULL;
    i++;

    char want_input='Y';
    printf("Ban co muon nhap tiep khong (Y/N)?");
    fflush(stdin);
    scanf("%c", &want_input);
    printf("%c\n", want_input);

    while(((want_input != 'N')&&(want_input != 'n'))) {   
        L->last->link = (Node*)malloc(sizeof(Node)); // cuối cũ
        L->last = L->last->link;// trỏ đến cuối mới
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
        L->last->link = NULL;
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
        p = p->link;
        i++;
    }
}

int compare()