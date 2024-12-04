#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int L[], int R[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int L[], int R[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, L, R, l, m);
        mergeSort(arr, L, R, m + 1, r);
        merge(arr, L, R, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int n_values[] = {20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000,
                      220000, 240000, 260000, 280000, 300000, 320000, 340000, 360000, 380000, 400000};
    int n_tests = sizeof(n_values) / sizeof(n_values[0]);
    FILE *fp = fopen("results400.csv", "w");
    fprintf(fp, "n,InsertionSort,MergeSort,QuickSort\n");
    srand(time(NULL));

    int *arr = malloc(400000 * sizeof(int)); 
    int *copy = malloc(400000 * sizeof(int));
    int *L = malloc(200000 * sizeof(int));  
    int *R = malloc(200000 * sizeof(int));  

    for (int i = 0; i < n_tests; i++) {
        int n = n_values[i];

        fillArray(arr, n);
        copyArray(arr, copy, n);
        clock_t start = clock();
        insertionSort(copy, n);  
        clock_t end = clock();
        double time_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;

        copyArray(arr, copy, n);
        start = clock();
        mergeSort(copy, L, R, 0, n - 1);
        end = clock();
        double time_merge = ((double)(end - start)) / CLOCKS_PER_SEC;

        copyArray(arr, copy, n);
        start = clock();
        quickSort(copy, 0, n - 1);
        end = clock();
        double time_quick = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "%d,%.6f,%.6f,%.6f\n", n, time_insertion, time_merge, time_quick);
        printf("Teste com n=%d concluído\n", n);
    }

    free(arr);
    free(copy);
    free(L);
    free(R);
    fclose(fp);
    printf("Gerou os dados com sucesso.\n");
    return 0;
}

