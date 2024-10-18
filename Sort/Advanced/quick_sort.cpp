#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân chia mảng, trả về chỉ số của phần tử chốt sau khi phân chia
int partition(std::vector<int>& arr, int begin, int end) {
    int pivot = arr[end];  // Chọn phần tử cuối cùng làm pivot
    int i = begin - 1;  // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = begin; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Đưa phần tử nhỏ hơn pivot về phía trước
        }
    }
    swap(arr[i + 1], arr[end]);  // Đặt pivot vào vị trí chính xác
    return i + 1;
}

// Hàm thực hiện QuickSort
void quickSort(std::vector<int>& arr, int begin, int end) {
    if (begin < end) {
        int pivotIndex = partition(arr, begin, end);  // Phân chia mảng
        quickSort(arr, begin, pivotIndex - 1);  // Sắp xếp mảng con bên trái
        quickSort(arr, pivotIndex + 1, end);  // Sắp xếp mảng con bên phải
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    
    std::cout << "Mảng ban đầu: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1); 

    std::cout << "Mảng sau khi sắp xếp: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
