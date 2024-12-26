#include <stdio.h>

int maxdivcom (int a, int b) {
    while (b!=0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplificar (int *num, int *den) {
    int divisor = maxdivcom( *num, *den);
    *num  /= divisor;
    *den /= divisor;

    if (*den < 0 ){
        *num = -*num;
        *den = -*den;
    }
}

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 0; i< n; i++) {
        int n1, d1, n2, d2;
        char op, barra;

        scanf("%d %c %d %c %d %c %d", &n1, &barra, &d1, &op, &n2, &barra, &d2); 

        int num_res, den_res;

        if (op == '+') {
            num_res = n1 * d2 + n2 * d1;
            den_res = d1 * d2;
        } else if (op == '-') {
            num_res = n1 * d2 - n2 * d1;
            den_res = d1 * d2;
        } else if (op == '*') {
            num_res = n1 * n2;
            den_res = d1 * d2;
        } else if (op == '/') {
            num_res = n1 * d2;
            den_res = n2 * d1;
        }

        printf ("%d/%d = ", num_res, den_res);
        simplificar(&num_res, &den_res);
        printf ("%d/%d\n", num_res, den_res);
    }
}
