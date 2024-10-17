#include <iostream>
#include <string.h>

int main(){
    std:: cout << "Nhap so cac doi tuong: ";
    int n;
    std:: cin >> n;
    std:: cout << "Nhap chuoi cac doi tuong: ";
    std:: string arr[10000];


    int count[3];
    count[0] = count[1] = count[2] = 0;
    for(int i = 0; i < n; i++){
        std:: cin >> arr[i];

        if(arr[i] == "Do"){
            count[0]++;
        }
        if(arr[i] == "Trang"){
            count[1]++;
        }
        if(arr[i] == "Xanh"){
            count[2]++;
        }
    }

    std:: string output_color;

    std:: cout << "Chuoi cac doi tuong da sap xep: ";

    for(int i = 0; i < 3; i++){
        while(count[i] > 0){
            switch (i){
                case 0:
                    output_color = "Do";
                    break;

                case 1:
                    output_color = "Trang";
                    break;

                case 2:
                    output_color = "Xanh";
                    break;
                default:
                    break;
            }
            std:: cout << output_color << " ";
            count[i]--;
        }
    }

}