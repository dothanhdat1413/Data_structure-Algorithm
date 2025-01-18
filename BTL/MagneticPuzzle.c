#include <stdio.h>
#include <stdbool.h> // Để sử dụng kiểu dữ liệu bool

#define M 5  // Số hàng (rows)
#define N 6  // Số cột (columns)

// Hàm in bảng 5×6
void printBoard(char board[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Đếm số ký tự `ch` trong cột `col`
int countCol(char board[M][N], char ch, int col) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (board[i][col] == ch) {
            count++;
        }
    }
    return count;
}

// Đếm số ký tự `ch` trong hàng `row`
int countRow(char board[M][N], char ch, int row) {
    int count = 0;
    for (int j = 0; j < N; j++) {
        if (board[row][j] == ch) {
            count++;
        }
    }
    return count;
}

// Kiểm tra xem có đặt được ký hiệu `ch` (+ hoặc -) tại (row,col) hay không
bool isValid(char board[M][N], int row, int col, char ch,
             int top[], int left[], int bottom[], int right[]) {
    // Kiểm tra 4 ô kề: không cho phép ô kề có cùng ký hiệu `ch`
    if ((row - 1 >= 0 && board[row - 1][col] == ch) ||  // ô trên
        (col + 1 < N && board[row][col + 1] == ch) ||   // ô phải
        (row + 1 < M && board[row + 1][col] == ch) ||   // ô dưới
        (col - 1 >= 0 && board[row][col - 1] == ch)) {  // ô trái
        return false;
    }

    // Đếm số ch trong hàng, cột
    int soChHang = countRow(board, ch, row);
    int soChCot  = countCol(board, ch, col);

    // Nếu ch = '+', kiểm tra ràng buộc top[col], left[row]
    if (ch == '+') {
        if (top[col] != -1 && soChCot >= top[col]) return false;
        if (left[row] != -1 && soChHang >= left[row]) return false;
    }

    // Nếu ch = '-', kiểm tra bottom[col], right[row]
    if (ch == '-') {
        if (bottom[col] != -1 && soChCot >= bottom[col]) return false;
        if (right[row] != -1 && soChHang >= right[row]) return false;
    }

    return true;
}

// Kiểm tra cuối cùng: các cột/hàng đã khớp số lượng +, - với top[], bottom[], left[], right[] chưa
bool checkWin(char board[M][N], int top[], int left[], int bottom[], int right[]) {
    for (int j = 0; j < N; j++) {
        if (top[j] != -1 && countCol(board, '+', j) != top[j]) return false;
        if (bottom[j] != -1 && countCol(board, '-', j) != bottom[j]) return false;
    }
    for (int i = 0; i < M; i++) {
        if (left[i] != -1 && countRow(board, '+', i) != left[i]) return false;
        if (right[i] != -1 && countRow(board, '-', i) != right[i]) return false;
    }
    return true;
}

// Hàm đệ quy backtracking đặt cặp +/-
bool tryMagnet(char board[M][N], int row, int col,
               int top[], int left[], int bottom[], int right[],
               char rules[M][N]) {
    if (row == M - 1 && col == N) {
        return checkWin(board, top, left, bottom, right);
    }

    if (col == N) {
        return tryMagnet(board, row + 1, 0, top, left, bottom, right, rules);
    }

    if (rules[row][col] == 'R' || rules[row][col] == 'B') {
        return tryMagnet(board, row, col + 1, top, left, bottom, right, rules);
    }

    if (rules[row][col] == 'L' && col + 1 < N && rules[row][col + 1] == 'R') {
        if (isValid(board, row, col, '+', top, left, bottom, right) &&
            isValid(board, row, col + 1, '-', top, left, bottom, right)) {
            board[row][col] = '+';
            board[row][col + 1] = '-';
            if (tryMagnet(board, row, col + 2, top, left, bottom, right, rules)) return true;
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
        if (isValid(board, row, col, '-', top, left, bottom, right) &&
            isValid(board, row, col + 1, '+', top, left, bottom, right)) {
            board[row][col] = '-';
            board[row][col + 1] = '+';
            if (tryMagnet(board, row, col + 2, top, left, bottom, right, rules)) return true;
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
    }

    if (rules[row][col] == 'T' && row + 1 < M && rules[row + 1][col] == 'B') {
        if (isValid(board, row, col, '+', top, left, bottom, right) &&
            isValid(board, row + 1, col, '-', top, left, bottom, right)) {
            board[row][col] = '+';
            board[row + 1][col] = '-';
            if (tryMagnet(board, row, col + 1, top, left, bottom, right, rules)) return true;
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }
        if (isValid(board, row, col, '-', top, left, bottom, right) &&
            isValid(board, row + 1, col, '+', top, left, bottom, right)) {
            board[row][col] = '-';
            board[row + 1][col] = '+';
            if (tryMagnet(board, row, col + 1, top, left, bottom, right, rules)) return true;
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }
    }

    if (tryMagnet(board, row, col + 1, top, left, bottom, right, rules)) {
        return true;
    }

    return false;
}

// Hàm chính “driver”: khởi tạo board, gọi đệ quy, in kết quả
void solveMagnet(int top[], int left[], int bottom[], int right[], char rules[M][N]) {
    char board[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 'X';
        }
    }

    if (!tryMagnet(board, 0, 0, top, left, bottom, right, rules)) {
        printf("Khong co loi giai\n");
    } else {
        printBoard(board);
    }
}

int main() {
    int top[N], bottom[N], left[M], right[M];
    char rules[M][N];

    printf("Nhap 6 gia tri top[] (so '+' moi cot, -1 neu khong gioi han):\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &top[i]);
    }

    printf("Nhap 6 gia tri bottom[] (so '-' moi cot, -1 neu khong gioi han):\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &bottom[i]);
    }

    printf("Nhap 5 gia tri left[] (so '+' moi hang, -1 neu khong gioi han):\n");
    for (int i = 0; i < M; i++) {
        scanf("%d", &left[i]);
    }

    printf("Nhap 5 gia tri right[] (so '-' moi hang, -1 neu khong gioi han):\n");
    for (int i = 0; i < M; i++) {
        scanf("%d", &right[i]);
    }

    printf("Nhap ma tran rules (5 hang, moi hang 6 ky tu):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &rules[i][j]);
        }
    }

    solveMagnet(top, left, bottom, right, rules);
    return 0;
}
