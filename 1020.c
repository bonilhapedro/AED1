#include <stdio.h>
 
int main() {
 
    int diasT;
    
    scanf("%d", &diasT);
    
    int anos = diasT/365;
    diasT %= 365;
    int meses = diasT/30;
    diasT %= 30;
    
    
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", diasT);
 
    return 0;
}
