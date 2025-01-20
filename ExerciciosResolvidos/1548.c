#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    int posicao;
} Aluno;

// Função de comparação para ordenar os alunos por nota em ordem decrescente
int compare(const void *a, const void *b) {
    return ((Aluno*)b)->nota - ((Aluno*)a)->nota;  // Ordem decrescente
}

int main() {
    int N;
    scanf("%d", &N);  // Número de casos de teste
    
    while (N--) {
        int M;
        scanf("%d", &M);  // Número de alunos

        Aluno alunos[M];
        
        // Leitura das notas e suas posições originais
        for (int i = 0; i < M; i++) {
            scanf("%d", &alunos[i].nota);
            alunos[i].posicao = i;
        }

        // Ordenação dos alunos por suas notas em ordem decrescente
        qsort(alunos, M, sizeof(Aluno), compare);

        // Contagem de alunos que não precisaram trocar de lugar
        int nao_mudaram = 0;
        for (int i = 0; i < M; i++) {
            if (alunos[i].posicao == i) {
                nao_mudaram++;
            }
        }

        // Saída da quantidade de alunos que não mudaram de posição
        printf("%d\n", nao_mudaram);
    }
    
    return 0;
}
