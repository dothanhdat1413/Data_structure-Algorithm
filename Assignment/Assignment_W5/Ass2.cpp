#include <iostream>
#include <vector>

#define MAX 100000

std:: vector <bool> prime(MAX, true);
std:: vector <int> blum_list;

void Prime(int n);
void Blum(int n);
int main() {
    int n;
    std:: cout << "Nhap so nguyen n: ";
    std:: cin >> n;
    Blum(n);
    int blum_list_size = blum_list.size();
    std:: cout << "Cac so Blum trong doan [1, " << n << "] la: ";
    for(int i = 0; i < blum_list_size; i++){
        std:: cout << blum_list[i] << " ";
    }
    std:: cout << std:: endl;

    int M;
    std:: cout << "Nhap so nguyen M de kiem tra: ";
    std:: cin >> M;
    if(Check_Blum(M) == true){
        std:: cout << M << " la so Blum trong day" << std:: endl;
    }
    else{
        std:: cout << M << " khong phai la so Blum trong day" << std:: endl;
    }

    return 0;
}

void Prime(int n){ // Tìm số nguyên tố trong đoạn [1, n]
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++){ // Sàng Eratosthenes
        if(prime[i] == true){ 
            for(int j = i * i; j <= n; j += i){ // Loại bỏ bội số của số nguyên tố i
                prime[j] = false;
            }
        }
    }
}

void Blum(int n){ // Tìm số Blum trong đoạn [1, n]
    Prime(n);
    {
        std:: vector<int> prime_list;
        prime_list.push_back(2);
        for(int i = 3; i <= n; i += 2){
            if(prime[i] == true){
                prime_list.push_back(i);
            }
        }
        int prime_list_size = prime_list.size();
        for(int i = 0; i < prime_list_size - 1; i++){ // chạy từ đầu đến trước cuối 1 số thì dừng
            for(int j = i + 1; j < prime_list_size; j++){
                if((prime_list[i] * prime_list[j]) % 4 == 3){
                    blum_list.push_back(prime_list[i] * prime_list[j]);
                }
            }
        }
    }

}

bool Check_Blum(int M){ // Kiem tra M co phai la so Blum trong đoạn ko
    int blum_list_size = blum_list.size();
    for(int i = 0; i < blum_list_size; i++){
        if(blum_list[i] == M){
            return true;
        }
    }
    return false;
}