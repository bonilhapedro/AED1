#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int freq[231] = {0}, i, h;
        for(i = 0; i < n; i++){
            scanf("%d",&h);
            freq[h]++;
        }
        int first = 1;
        for(i = 20; i <= 230; i++){
            while(freq[i]--){
                if(first){ printf("%d", i); first = 0; }
                else printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
