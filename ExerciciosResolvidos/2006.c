#include <stdio.h>
 
int main() {
 
    int T, resultado = 0;
    int vetor[5];
    
    scanf("%d", &T);
    scanf("%d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4]);
    
    
    for (int i = 0; i<5; i++){
        if (T==vetor[i]){
            resultado++;
        }
    }
    
    printf("%d\n", resultado);
 
    return 0;
}
