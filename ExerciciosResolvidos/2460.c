#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
} Fila;

Fila* criarFila(int tamanho) {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (int*)malloc(tamanho * sizeof(int));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = tamanho;
    return fila;
}

void enfileirar(Fila *fila, int valor) {
    fila->dados[fila->fim++] = valor;
}

int filaVazia(Fila *fila) {
    return fila->inicio == fila->fim;
}

int desenfileirar(Fila *fila) {
    return fila->dados[fila->inicio++];
}

int main() {
    int N, M;
    scanf("%d", &N);

    Fila *fila = criarFila(N);
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        enfileirar(fila, id);
    }

    scanf("%d", &M);
    int *sairam = (int*)malloc(M * sizeof(int));
    int *presentes = (int*)calloc(100001, sizeof(int));
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        sairam[i] = id;
        presentes[id] = 1;
    }

    Fila *estado_final = criarFila(N - M);
    while (!filaVazia(fila)) {
        int pessoa = desenfileirar(fila);
        if (!presentes[pessoa]) {
            enfileirar(estado_final, pessoa);
        }
    }

    int primeiro = 1;
    while (!filaVazia(estado_final)) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", desenfileirar(estado_final));
        primeiro = 0;
    }
    printf("\n");

    free(fila->dados);
    free(fila);
    free(sairam);
    free(presentes);
    free(estado_final->dados);
    free(estado_final);

    return 0;
}
