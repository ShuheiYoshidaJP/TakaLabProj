#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4 // 要素数
#define EPS 0.01
#define MAX 1000

// 配列を引数にする時
// https://www.sejuku.net/blog/24359

// 配列を戻り値にする時
// https://www.sejuku.net/blog/24348

void cg(double A[N][N], double b[N]);
double *matrix_x_vector(double A[N][N], double b[N]);
double *matrix_x_vector(double A[N][N], double b[N]);
double vector_product(double A[N], double B[N]);
double vector_norm(double vector[N]);
void output_matrix(double A[N][N]);
void output_vector(double b[N]);

// main function
void cg(double A[N][N], double b[N]) {
    // https://www.kz.tsukuba.ac.jp/~abe/ohp-cfd/cfd03_tanaka_H28.pdf
    int count = 0;
    double x[N] = {0, 0, 0, 0};
    double gamma[N];
    double p[N];
    double alpha_ue;
    double alpha_shita;
    double alpha;
    double Ap[N];
    double beta;
    double beta_ue;
    double beta_shita;

    double Ax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Ax += A[i][j] * x[j];
        }
        gamma[i] = b[i] - Ax;
        Ax = 0;
    }
    p = gamma;

    while (vector_norm(gamma) < EPS) {
        // alpha = alpha_ue/alpha_shita
        Ap = matrix_x_vector(A, p);
        alpha_ue = vector_product(p, gamma);
        alpha_shita = vector_product(p, Ap);
        alpha = alpha_ue / alpha_shita;

        for (size_t i = 0; i < N; i++) {
            x[i] = x[i] + alpha * p[i];
            gamma[i] = gamma[i] - alpha * Ap[i];
        }

        beta_ue = vector_product(gamma, Ap);
        beta_shita = vector_product(p, Ap);
        beta = (-1) * beta_ue / beta_shita;

        for (size_t i = 0; i < N; i++) {
            p[i] = gamma[i] + beta * p[i];
        }
        if (count > MAX) {
            printf("許容回数超えました\n");
            break;
        }
        count++;
    }

    output_vector(x);
}

// calculate
double *matrix_x_vector(double A[N][N], double b[N]) {
    double *result = malloc(N);
    double value = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            value += A[i][j] * b[j];
        }
        result[i] = value;
        value = 0;
    }
    return result;
}

double vector_product(double A[N], double B[N]) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }
    return result;
}

double vector_norm(double vector[N]) {
    double norm = 0;
    for (int i = 0; i < N; i++) {
        if (vector[i] <= 0) {
            norm += vector[i];
        } else {
            norm += (vector[i] * (-1));
        }
    }
    return norm;
}

// output
void output_matrix(double A[N][N]) {
    for (int m = 0; m < N; m++) {
        printf(" ");
        for (int n = 0; n < N; n++) {
            printf(" %f", A[m][n]);
        }
        printf("\n");
    }
}

void output_vector(double b[N]) {
    for (size_t n = 0; n < N; n++) {
        printf(" %f\n", b[n]);
    }
}

int main(void) {
    // http://www-section.cocolog-nifty.com/blog/2008/12/cg-f85b.html
    double A[N][N] = {{2, 4, 0, 0}, {4, 8, 2, 2}, {0, 2, 1, 0}, {0, 2, 0, 4}};
    double b[N] = {2, 1, 4, 5};
    cg(A, b);
    return 0;
}
