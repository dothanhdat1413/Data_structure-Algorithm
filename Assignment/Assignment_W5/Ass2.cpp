#include <iostream>
#include <vector>

#define MAX 100000

std:: vector <bool> prime(MAX, true);

void Prime(int n);
void Blum(int n);
int main() {

}

void Prime(int n){
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++){ // Sàng Eratosthenes
        if(prime[i] == true){ 
            for(int j = i * i; j <= n; j += i){ // Loại bỏ bội số của số nguyên tố i
                prime[j] = false;
            }
        }
    }
}

void Blum(int n){
    Prime(n);
    int blum = 0;
    for(int i = 2; i <= n; i++){ // Tìm bội số của số nguyên tố
}