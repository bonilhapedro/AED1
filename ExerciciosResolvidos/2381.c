#include <stdio.h>
#include <string.h>

void merge(char names[][21], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][21], R[n2][21];

    for (i = 0; i < n1; i++) {
        strcpy(L[i], names[left + i]);
    }
    for (j = 0; j < n2; j++) {
        strcpy(R[j], names[mid + 1 + j]);
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(names[k], L[i]);
            i++;
        } else {
            strcpy(names[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(names[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(names[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char names[][21], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(names, left, mid);
        mergeSort(names, mid + 1, right);
        merge(names, left, mid, right);
    }
}

int main() {
    int N, K;
    char names[100][21];

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%s", names[i]);
    }

    mergeSort(names, 0, N - 1);

    printf("%s\n", names[K - 1]);

    return 0;
}
