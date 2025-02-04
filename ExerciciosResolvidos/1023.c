#include <stdio.h>
#include <math.h>

int main() {
    int n, cidade = 1;
    
    while (scanf("%d", &n) == 1 && n) {
        if (cidade > 1)
            printf("\n");
        
        int grupo[201] = {0}, totalMor = 0, totalCons = 0;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            totalMor += x;
            totalCons += y;
            grupo[y / x] += x;
        }
        
        printf("Cidade# %d:\n", cidade);
        
        int primeiro = 1;
        for (int i = 0; i <= 200; i++) {
            if (grupo[i]) {
                if (!primeiro)
                    printf(" ");
                printf("%d-%d", grupo[i], i);
                primeiro = 0;
            }
        }
        
        double media = (double) totalCons / totalMor;
        media = ((int)(media * 100)) / 100.0;
        printf("\nConsumo medio: %.2f m3.\n", media);
        
        cidade++;
    }
    
    return 0;
}
