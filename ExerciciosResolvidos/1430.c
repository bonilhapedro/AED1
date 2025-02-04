#include <stdio.h>
#include <string.h>

int main(void) {
    char composicao[210];

    while (fgets(composicao, sizeof(composicao), stdin) != NULL) {
        int len = strlen(composicao);
        if (composicao[len - 1] == '\n')
            composicao[len - 1] = '\0';

        if (composicao[0] == '*' && composicao[1] == '\0')
            break;

        int compassosValidos = 0;
        int duracao = 0;

        for (int i = 1; composicao[i] != '\0'; i++) {
            if (composicao[i] == '/') {
                if (duracao == 64)
                    compassosValidos++;
                duracao = 0;
            } else {
                switch (composicao[i]) {
                    case 'W': duracao += 64; break;
                    case 'H': duracao += 32; break;
                    case 'Q': duracao += 16; break;
                    case 'E': duracao += 8;  break;
                    case 'S': duracao += 4;  break;
                    case 'T': duracao += 2;  break;
                    case 'X': duracao += 1;  break;
                }
            }
        }
        printf("%d\n", compassosValidos);
    }
    return 0;
}
