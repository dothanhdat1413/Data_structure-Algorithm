#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cây AVL
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Hàm để tính chiều cao của cây
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Hàm để tính cân bằng của cây
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Hàm tạo một node mới
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Hàm thực hiện phép xoay đơn trái
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;

    // Trả về node mới
    return y;
}

// Hàm thực hiện phép xoay đơn phải
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;

    // Trả về node mới
    return x;
}

// Hàm thực hiện phép xoay kép trái phải
Node* rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Hàm thực hiện phép xoay kép phải trái
Node* rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Hàm thêm node vào cây AVL
Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    // Thêm node vào cây theo quy tắc nhị phân
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // Không thêm phần tử trùng

    // Cập nhật chiều cao của node
    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    // Kiểm tra và cân bằng lại cây nếu cần
    int balance = getBalance(node);

    // Nếu cây bị mất cân bằng, có 4 trường hợp

    // Xoay đơn trái
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Xoay đơn phải
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Xoay kép trái phải
    if (balance > 1 && key > node->left->key)
        return rotateLeftRight(node);

    // Xoay kép phải trái
    if (balance < -1 && key < node->right->key)
        return rotateRightLeft(node);

    return node;
}

// Hàm in cây theo thứ tự trung tự
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Hàm in cây theo thứ tự tiền tự
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Hàm in cây theo thứ tự hậu tự
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    Node* root = NULL;
    int testVector[] = {210, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    int n = sizeof(testVector) / sizeof(testVector[0]);

    // Thêm các phần tử vào cây AVL và in cây sau mỗi bước
    for (int i = 0; i < n; i++) {
        root = insert(root, testVector[i]);
        printf("After inserting %d:\n", testVector[i]);
        printf("Inorder: ");
        inorder(root);
        printf("\nPreorder: ");
        preorder(root);
        printf("\nPostorder: ");
        postorder(root);
        printf("\n\n");
    }

    return 0;
}
