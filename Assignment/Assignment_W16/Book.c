#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    char name[100];          
    int startPage;             
    int endPage;               
    struct Node* next;          
    struct Node* firstChild;    
} Node;

// Hàm tạo node mới
Node* createNode(const char* name, int startPage, int endPage) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->startPage = startPage;
    newNode->endPage = endPage;
    newNode->next = NULL;
    newNode->firstChild = NULL;
    return newNode;
}

// Hàm thêm mục con vào cây (children)
void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

// Hàm tính số chương trong cuốn sách
int countChapters(Node* root) {
    int count = 0;
    Node* temp = root;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hàm tìm chương dài nhất trong cuốn sách
Node* findLongestChapter(Node* root) {
    Node* temp = root;
    Node* longest = NULL;
    int maxPages = 0;

    while (temp != NULL) {
        int chapterLength = temp->endPage - temp->startPage;
        if (chapterLength > maxPages) {
            maxPages = chapterLength;
            longest = temp;
        }
        temp = temp->next;
    }
    return longest;
}

// Hàm tìm một mục theo tên và xóa nó
Node* findAndDelete(Node* root, const char* name) {
    Node *temp = root, *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) { // Xóa node đầu tiên
                root = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return root;
        }
        prev = temp;
        temp = temp->next;
    }
    return root;
}

// Hàm cập nhật số trang của các mục con sau khi xóa
void updatePages(Node* root) {
    Node* temp = root;
    int currentPage = root->startPage;
    
    while (temp != NULL) {
        temp->startPage = currentPage;
        currentPage = temp->endPage + 1;
        
        // Cập nhật cho các mục con (nếu có)
        Node* child = temp->firstChild;
        while (child != NULL) {
            child->startPage = currentPage;
            currentPage = child->endPage + 1;
            child = child->next;
        }

        temp = temp->next;
    }
}

// Hàm hiển thị cây sách
void printBook(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        printf("Muc: %s, Trang bat dau: %d, Trang ket thuc: %d\n", temp->name, temp->startPage, temp->endPage);
        Node* child = temp->firstChild;
        while (child != NULL) {
            printf("  Muc con: %s, Trang bat dau: %d, Trang ket thuc: %d\n", child->name, child->startPage, child->endPage);
            child = child->next;
        }
        temp = temp->next;
    }
}

int main() {
    // Tạo ra cây sách
    Node* book = createNode("Chapter 1", 1, 10);
    Node* chapter2 = createNode("Chapter 2", 11, 20);
    Node* chapter3 = createNode("Chapter 3", 21, 30);

    // Thêm các mục con
    Node* section1 = createNode("Section 1", 1, 5);
    Node* subsection1 = createNode("Subsection 1", 1, 3);
    addChild(section1, subsection1);
    addChild(book, section1);

    Node* section2 = createNode("Section 2", 6, 10);
    addChild(book, section2);

    addChild(book, chapter2);
    addChild(book, chapter3);

    // In ra thông tin sách ban đầu
    printf("Thong tin sach:\n");
    printBook(book);

    // Xác định số chương của cuốn sách
    printf("\nSo chuong: %d\n", countChapters(book));

    // Tìm chương dài nhất
    Node* longestChapter = findLongestChapter(book);
    if (longestChapter != NULL) {
        printf("\nChuong dai nhat: %s, voi %d trang.\n", longestChapter->name, longestChapter->endPage - longestChapter->startPage);
    }

    // Tìm và xóa một mục
    printf("\n Xoa muc 'Section 1':\n");
    book = findAndDelete(book, "Section 1");
    updatePages(book);
    printBook(book);

    return 0;
}
