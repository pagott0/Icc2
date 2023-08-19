#include <stdio.h>


void bolha(int a[], int n){
    int c;
    for(int i = n-1; i >=1; i = c){
        c = -1;
        for(int j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                c = j;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int originalArray[5];

    originalArray[0] = 1;
    originalArray[1] = 4;
    originalArray[2] = 2;
    originalArray[3] = 3;
    originalArray[4] = 5;

    bolha(originalArray, 5);

    for(int i = 0; i < 5; i++){
        printf("%d\n", originalArray[i]);
    }

}

