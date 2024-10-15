#include <stdio.h>

int main() {
    int T, resultado = 0;
    int vetor[5];

    scanf("%d", &T);

    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (vetor[i] == T) {
            resultado++;
        }
    }

    printf("%d\n", resultado);
    return 0;
}
