#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixaParaPosfixa(char* infixa, char* posfixa) {
    char pilha[MAX];
    int topo = -1;
    int j = 0;
    
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];
        
        if (isalnum(c)) {
            posfixa[j++] = c;
        } else if (c == '(') {
            pilha[++topo] = c;
        } else if (c == ')') {
            while (topo >= 0 && pilha[topo] != '(') {
                posfixa[j++] = pilha[topo--];
            }
            topo--;
        } else {
            while (topo >= 0 && precedencia(pilha[topo]) >= precedencia(c)) {
                posfixa[j++] = pilha[topo--];
            }
            pilha[++topo] = c;
        }
    }
    
    while (topo >= 0) {
        posfixa[j++] = pilha[topo--];
    }
    
    posfixa[j] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++) {
        char infixa[MAX], posfixa[MAX];
        fgets(infixa, MAX, stdin);
        infixa[strcspn(infixa, "\n")] = 0;
        
        infixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }
    
    return 0;
}
