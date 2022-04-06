#include <stdio.h>
#include <stdlib.h>

#define N 4 // 要素数

typedef double Vector[N];
typedef double Matrix[N][N];


void cg(Matrix A, Matrix b, double epsilon) {
    // https://www.kz.tsukuba.ac.jp/~abe/ohp-cfd/cfd03_tanaka_H28.pdf
    
}



int main(void) {
    // http://www-section.cocolog-nifty.com/blog/2008/12/cg-f85b.html
    Matrix A = {{2, 4, 0, 0}, {4, 8, 2, 2}, {0, 2, 1, 0}, {0, 2, 0, 4}};
    Vector b = {{2}, {1}, {4}, {5}}
    cg();
    return 0;
}
