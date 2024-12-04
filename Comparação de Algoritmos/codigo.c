#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
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

int main() {
    int n_values[] = {20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000};
    int n_tests = sizeof(n_values) / sizeof(n_values[0]);
    FILE *fp = fopen("results.csv", "w");
    fprintf(fp, "n,InsertionSort,MergeSort,QuickSort\n");
    srand(time(NULL));

    for (int i = 0; i < n_tests; i++) {
        int n = n_values[i];
        int *arr = malloc(n * sizeof(int));
        clock_t start, end;

        fillArray(arr, n);
        start = clock();
        insertionSort(arr, n);
        end = clock();
        double time_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;

        fillArray(arr, n);
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_merge = ((double)(end - start)) / CLOCKS_PER_SEC;

        fillArray(arr, n);
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        double time_quick = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "%d,%.6f,%.6f,%.6f\n", n, time_insertion, time_merge, time_quick);

        free(arr);
    }

    fclose(fp);
    return 0;
}
