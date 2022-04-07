#include <stdio.h>
#include <stdlib.h>

#define N 4 // 要素数

typedef double Vector[N];
typedef double Matrix[N][N];

// 配列を引数にする時
// https://www.sejuku.net/blog/24359

// 配列を戻り値にする時
// https://www.sejuku.net/blog/24348

// main function
void cg(Matrix A, Matrix b, double epsilon) {
    // https://www.kz.tsukuba.ac.jp/~abe/ohp-cfd/cfd03_tanaka_H28.pdf

}

// calculate
Vector *matrix_x_vector(Matrix *A, Vector *b) {
    static Vector result;
    static double value = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("i=%d j=%d\n", i, j);
            printf("a=%f, b=%f\n", *A[i][j], *b[j]);
            //value += A[i][j] * b[j];
        }
        result[i] = value;
        value = 0;
    }
    return &result;
}

// output
void output_matrix(Matrix **A) {
    for (int m = 0; m < N; m++) {
        printf(" ");
        for (int n = 0; n < N; n++) {
            printf(" %f", A[m][n]);
        }
        printf("\n");
    }
}

void output_vector(Vector *b) {
    for (size_t n = 0; n < N; n++) {
        printf(" %f\n", *b[n]);
    }
}


int main(void) {
    // http://www-section.cocolog-nifty.com/blog/2008/12/cg-f85b.html
    Matrix A = {{2, 4, 0, 0}, {4, 8, 2, 2}, {0, 2, 1, 0}, {0, 2, 0, 4}};
    Vector b = {2, 1, 4, 5};
    Vector *result = matrix_x_vector(&A, &b);
    output_vector(result);
    output_matrix(A);
    return 0;
}
