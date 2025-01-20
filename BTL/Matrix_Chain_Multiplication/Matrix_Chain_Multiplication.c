#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // sử dụng để test

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

/**
 * @brief Tính toán chi phí tối thiểu để nhân chuỗi ma trận bằng Quy hoạch động (DP).
 *
 * @param dims Mảng kích thước các ma trận.
 * @param n    Số lượng phần tử trong mảng dims.
 * @return     Chi phí tối thiểu để nhân chuỗi ma trận.
 */
int matrixChainMultiplication_DP(int dims[], int n) {
    // DP sử dụng 1 mảng tra cứu
    int **lookup = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        lookup[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            lookup[i][j] = 0; 
        }
    }

    // Thực hiện DP theo hàm DP của công thức truy hồi
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

    // Kết quả cuối cùng lưu tại phần tử cột cuối cùng của hàng đầu tiên trong mảng tra cứu
    int result = lookup[0][n - 1];

    for (int i = 0; i < n; i++) {
        free(lookup[i]);
    }
    free(lookup);

    return result;
}

/**
 * @brief Tính toán chi phí tối thiểu để nhân chuỗi ma trận bằng Hu-Shing (chia để trị).
 *
 * @param dims Mảng kích thước các ma trận.
 * @param i    Chỉ số bắt đầu của đoạn.
 * @param j    Chỉ số kết thúc của đoạn.
 * @return     Chi phí tối thiểu để nhân chuỗi ma trận trong đoạn [i, j].
 */
int matrixChainMultiplication_HuShing(int dims[], int i, int j) {
    // Kiểm tra input
    if (j - i <= 1) {
        return 0;
    }
    int minCost = INT_MAX;

    // Duyệt qua tất cả các cách chia đoạn tại các điểm từ i+1 đến j-1
    for (int k = i + 1; k < j; k++) {
        // Tính chi phí tam giác tại điểm chia k
        int cost = dims[i] * dims[k] * dims[j];

        // Tính chi phí của hai đoạn con bằng cách gọi đệ quy, đây là phần chia để trị
        int leftCost = matrixChainMultiplication_HuShing(dims, i, k);
        int rightCost = matrixChainMultiplication_HuShing(dims, k, j);

        // Tổng chi phí
        int totalCost = cost + leftCost + rightCost;

        // Cập nhật chi phí tối thiểu
        if (totalCost < minCost) {
            minCost = totalCost;
        }
    }

    return minCost;
}

int main() {
    // Kích thước các ma trận: 10x30, 30x5, 5x60
    int dims[] = {10, 30, 5, 60};
    int n = sizeof(dims) / sizeof(dims[0]);

    // Tính toán và in kết quả với Dynamic Programming
    int result_DP = matrixChainMultiplication_DP(dims, n);
    printf("Minimum cost using DP: %d\n", result_DP);

    // Tính toán và in kết quả với Hu-Shing 
    int result_HuShing = matrixChainMultiplication_HuShing(dims, 0, n - 1);
    printf("Minimum cost using Hu-Shing: %d\n", result_HuShing);

    // So sánh kết quả
    assert(result_DP == result_HuShing);
    printf("Both algorithms give the same result.\n");

    return 0;
}
