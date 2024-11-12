#include <stdio.h>
#include <string.h>


const char* verifica_parenteses(const char* expressao) {
    int pilha = 0;
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha++;
        } else if (expressao[i] == ')') {
            if (pilha == 0) {
                return "incorrect";
            }
            pilha--;
        }
    }
    
    return (pilha == 0) ? "correct" : "incorrect";
}

int main() {
    char expressao[1001];

    while (fgets(expressao, 1001, stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0';
        printf("%s\n", verifica_parenteses(expressao));
    }

    return 0;
}
