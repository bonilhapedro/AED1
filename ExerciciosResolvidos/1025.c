#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findFirst(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            res = mid;
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    int case_num = 1;
    int N, Q;
    
    while (1) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;
        
        int marbles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }
        
        qsort(marbles, N, sizeof(int), compare);
        
        printf("CASE# %d:\n", case_num);
        case_num++;
        
        for (int q = 0; q < Q; q++) {
            int x;
            scanf("%d", &x);
            int pos = findFirst(marbles, N, x);
            
            if (pos == -1) {
                printf("%d not found\n", x);
            } else {
                printf("%d found at %d\n", x, pos + 1);
            }
        }
    }
    
    return 0;
}
