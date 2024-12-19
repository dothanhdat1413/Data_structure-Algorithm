#include <iostream>
#include <vector>

std:: vector <int> c;
void merge(std:: vector <int> &a, std:: vector <int> &b);
int main(){

    std:: vector <int> a = {1, 3, 5, 7, 9};
    std:: vector <int> b = {2, 4, 6, 8, 10};
    merge(a, b);
    for(int i = 0;i < c.size();i++){
        std:: cout << c[i] << " ";
    }
    return 0;

}

void merge(std:: vector <int> &a, std:: vector <int> &b){
    int a_size = a.size();
    int b_size = b.size();
    int i, j;
    i = j = 0;
    for(int i = 0;i < a_size;i++){
        if(j < b_size) {
            while(a[i] > b[j]){
                c.push_back(b[j]);
                j ++;
            }
            c.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }
    if(j < b_size){
        c.push_back(b[j]);
        j ++;
    }

}

