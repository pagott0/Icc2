#include <stdio.h>

void merge(int arr[], int l, int m, int r, int *trocas, int *comparacoes)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        *comparacoes = *comparacoes + 1;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            
        }
        *trocas = *trocas + 1;
        k++;
        
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        *trocas = *trocas + 1;
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
      *trocas = *trocas + 1;
        j++;
        k++;
    }

    k = 0;
    for(int z = l; z <= r; z++, k++) {
      *trocas = *trocas + 1;
      R[z] = arr[z];
    }

  
}

void mergeSort(int arr[], int l, int r, int *trocas, int *comparacoes)
{   
    
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m, trocas, comparacoes);
        mergeSort(arr, m + 1, r, trocas, comparacoes);
 
        merge(arr, l, m, r, trocas, comparacoes);
    }
    
}

void insertionSort(int arr[], int n)
{
    int trocas = 0, comparacoes = 0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        trocas++;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            trocas++;
            comparacoes++;
        }
        if(j >= 0 && key >= arr[j]){
          comparacoes++;
        }
        arr[j + 1] = key;
        trocas++;
    }
    printf("I %d %d %d\n", n, trocas, comparacoes);
}

int main () {
  int q;
  scanf("%d", &q);
  int v[q][100];
  int sizes[100] = {0};

  for(int i = 0; i < q; i++) {
    int temp;
    scanf("%d", &temp);
    sizes[i] = temp;
    /* for(int j = 0; j < temp; j++) {
      scanf("%d", &v[i][j]);
    } */
  }
  int k;
  while(sizes[k] != 0){
    for(int j = 0; j < sizes[k]; j++) {
      scanf("%d", &v[k][j]);
    }
    k++;
  }

  for(int i = 0; i < q; i++) {
        insertionSort(v[i], sizes[i]);
        int mergeTrocas = 0, mergeComparacoes = 0;
        mergeSort(v[i], 0, sizes[i] - 1, &mergeTrocas, &mergeComparacoes);
        printf("M %d %d %d\n", sizes[i], mergeTrocas, mergeComparacoes);
  }

}
