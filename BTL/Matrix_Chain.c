#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Hàm tính số phép toán tối thiểu cho Matrix Chain Multiplication
int matrixChainMultiplication(int dims[], int n) {
    // Cấp phát bộ nhớ động cho bảng tra cứu
    int **lookup = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        lookup[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            lookup[i][j] = 0; // Khởi tạo giá trị 0
        }
    }

    // Tính toán bằng Dynamic Programming
    for (int length = 2; length < n; length++) { // length: độ dài đoạn
        for (int i = 0; i < n - length; i++) {
            int j = i + length;  // Điểm cuối của đoạn
            lookup[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = lookup[i][k] + lookup[k][j] + dims[i] * dims[k] * dims[j];
                if (cost < lookup[i][j]) {
                    lookup[i][j] = cost;
                }
            }
        }
    }

    // Kết quả cuối cùng
    int result = lookup[0][n - 1];

    // Giải phóng bộ nhớ động
    for (int i = 0; i < n; i++) {
        free(lookup[i]);
    }
    free(lookup);

    return result;
}

int main() {
    // Kích thước các ma trận: 10x30, 30x5, 5x60
    int dims[] = {10, 30, 5, 60};
    int n = sizeof(dims) / sizeof(dims[0]);

    // Tính toán và in kết quả
    int result = matrixChainMultiplication(dims, n);
    printf("The minimum cost is %d\n", result);

    return 0;
}
