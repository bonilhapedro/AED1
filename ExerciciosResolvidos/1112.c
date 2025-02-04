#include <stdio.h>
int BIT[1100][1100];
void update(int x, int y, int val, int n, int m) {
    for(; x <= n; x += x & -x)
        for(int j = y; j <= m; j += j & -j)
            BIT[x][j] += val;
}
int query(int x, int y) {
    int s = 0;
    for(; x; x -= x & -x)
        for(int j = y; j; j -= j & -j)
            s += BIT[x][j];
    return s;
}
int main(){
    int X, Y, P;
    while(scanf("%d %d %d", &X, &Y, &P) == 3){
        if(X == 0 && Y == 0 && P == 0) break;
        int n = X, m = Y, Q;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                BIT[i][j] = 0;
        scanf("%d", &Q);
        while(Q--){
            char op;
            scanf(" %c", &op);
            if(op == 'A'){
                int nVal, x, y;
                scanf("%d %d %d", &nVal, &x, &y);
                update(x + 1, y + 1, nVal, n, m);
            } else {
                int x, y, z, w;
                scanf("%d %d %d %d", &x, &y, &z, &w);
                int x1 = x < z ? x : z, y1 = y < w ? y : w, x2 = x > z ? x : z, y2 = y > w ? y : w;
                int s = query(x2 + 1, y2 + 1) - query(x1, y2 + 1) - query(x2 + 1, y1) + query(x1, y1);
                printf("%d\n", s * P);
            }
        }
        printf("\n");
    }
    return 0;
}
