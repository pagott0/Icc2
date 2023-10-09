#include <stdio.h>

#define MAX_SIZE 1000


void shell(int v[], int n, int* shellOperationsCount) {

    int gap = 1;

    while(gap <= n) {

        gap *= 2;

    }

    gap = gap / 2 - 1;

    while(gap > 0) {

            for (int i = gap; i < n; i++){

                int x = v[i];
                *shellOperationsCount = *shellOperationsCount + 1;

                int j = i - gap;

                while(j >= 0 && v[j] > x) {
                    *shellOperationsCount = *shellOperationsCount + 1;
                    
                    v[j + gap] = v[j];
                    *shellOperationsCount = *shellOperationsCount + 1;

                    j -= gap;

                }
                if (j >= 0) {
                *shellOperationsCount = *shellOperationsCount + 1;
            }

                v[j + gap] = x;
                *shellOperationsCount = *shellOperationsCount + 1;

            }

        gap /= 2;

    }

}

void quick(int v[], int f, int l, int* quickOperationsCount) {

        if (f >= l) {
            return;
        }

        int m = (l + f)/2;

        int pivot = v[m];
        *quickOperationsCount = *quickOperationsCount + 1;

        int i = f;

        int j = l;

        while(1) {

                while(v[i] < pivot) {
                        *quickOperationsCount = *quickOperationsCount + 1;
                        i++;
                }
                *quickOperationsCount = *quickOperationsCount + 1;

                while(v[j] > pivot) {
                        *quickOperationsCount = *quickOperationsCount + 1;
                        j--;
                }
                *quickOperationsCount = *quickOperationsCount + 1;
            
                if (i >= j) {
                        break;
                }

                int aux = v[i];

                v[i] = v[j];

                v[j] = aux;
                *quickOperationsCount = *quickOperationsCount + 3;

                i++;
                j--;

        }

        quick(v, f, j, quickOperationsCount);

        quick(v, j+1, l, quickOperationsCount);

    }

int main()
{   
    int n;
    scanf("%d", &n);
    int v[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    


    int subArrays[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            subArrays[i][j] = v[j];
        }
    }

    for (int i = 0; i < n; i++) {
        int shellOperationsCount = 0, quickOperationsCount = 0;
        int shellSubArray[MAX_SIZE]; 
        int quickSubArray[MAX_SIZE]; 

        for (int j = 0; j < i + 1; j++) {
            shellSubArray[j] = subArrays[i][j];
            quickSubArray[j] = subArrays[i][j];
        }

        shell(shellSubArray, i + 1, &shellOperationsCount);
        quick(quickSubArray, 0, i, &quickOperationsCount);
        
        //printf("QUICK: %d\n", quickOperationsCount);
        //printf("SHELL: %d\n", shellOperationsCount);

        if (shellOperationsCount == quickOperationsCount) {
            printf("-");
        } else if (shellOperationsCount < quickOperationsCount) {
            printf("S");
        } else {
            printf("Q");
        }
    }

    return 0;
}
