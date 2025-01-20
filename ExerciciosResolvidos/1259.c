#include <stdio.h>
#include <stdlib.h>

int compare_int_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Ordena em ordem crescente
}

int compare_int_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);  // Ordena em ordem decrescente
}

int main() {
    int N;
    scanf("%d", &N);
    
    int pares[N], impares[N];
    int num_pares = 0, num_impares = 0;

    // Leitura dos números e separação em pares e ímpares
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            pares[num_pares++] = num;  // Adiciona aos pares
        } else {
            impares[num_impares++] = num;  // Adiciona aos ímpares
        }
    }

    // Ordenação dos pares em ordem crescente
    qsort(pares, num_pares, sizeof(int), compare_int_asc);
    
    // Ordenação dos ímpares em ordem decrescente
    qsort(impares, num_impares, sizeof(int), compare_int_desc);
    
    // Impressão dos pares ordenados
    for (int i = 0; i < num_pares; i++) {
        printf("%d\n", pares[i]);
    }

    // Impressão dos ímpares ordenados
    for (int i = 0; i < num_impares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
