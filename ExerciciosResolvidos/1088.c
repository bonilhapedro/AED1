#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right);

long long merge_and_count(int arr[], int temp[], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        count += merge_and_count(arr, temp, left, mid);
        count += merge_and_count(arr, temp, mid + 1, right);

        count += merge(arr, temp, left, mid, right);
    }
    return count;
}

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int arr[n], temp[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        long long inv_count = merge_and_count(arr, temp, 0, n - 1);

        if (inv_count % 2 == 1) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }
    return 0;
}
