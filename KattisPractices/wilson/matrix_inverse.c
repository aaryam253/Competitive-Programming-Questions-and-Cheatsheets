#include <stdio.h>

int determinant (int mtx[][2]) {
    return mtx[0][0] * mtx[1][1] - mtx[0][1] * mtx[1][0];
}


int main () {
    int mtx[2][2];
    int numCases = 0;
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
        numCases++;
        mtx[0][0] = a;
        mtx[0][1] = b;
        mtx[1][0] = c;
        mtx[1][1] = d;
        
        int det = determinant(mtx);
        
        int t = mtx[0][0];
        mtx[0][0] = mtx[1][1];
        mtx[1][1] = t;
        mtx[0][1] *= -1;
        mtx[1][0] *= -1;
        printf("Case %d:\n", numCases);

        for (int i = 0; i < 2; i++) {
            for (int d = 0; d < 2; d++) {
                mtx[i][d] /= det;
                printf("%d ", mtx[i][d]);
            }
            printf("\n");
        }
    }
    
    
    
}
