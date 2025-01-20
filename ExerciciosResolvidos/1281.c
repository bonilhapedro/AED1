#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 1000
#define MAX_NOME 51

typedef struct {
    char nome[51];
    float preco;
} Produto;

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        Produto produtos[M];

        for (int i = 0; i < M; i++) {
            scanf("%s %f", produtos[i].nome, &produtos[i].preco);
        }

        int P;
        scanf("%d", &P);

        float total = 0.0;

        for (int i = 0; i < P; i++) {
            char nome_produto[51];
            int quantidade;
            scanf("%s %d", nome_produto, &quantidade);

            for (int j = 0; j < M; j++) {
                if (strcmp(produtos[j].nome, nome_produto) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", total);
    }

    return 0;
}
