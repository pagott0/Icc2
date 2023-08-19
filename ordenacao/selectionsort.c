#include <stdio.h>


void selecao(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int m = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[m]){
                m = j;
            }
        }
    
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
    
}

//1 4 2 3 5

int main() {
    
    //testing below
    int originalArray[5];

    originalArray[0] = 1;
    originalArray[1] = 4;
    originalArray[2] = 2;
    originalArray[3] = 3;
    originalArray[4] = 5;

    selecao(originalArray, 5);

    for(int i = 0; i < 5; i++){
        printf("%d\n", originalArray[i]);
    }

}

