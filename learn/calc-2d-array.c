#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 4

// 領域の確保
double **dmatrix(int row_count, int col_count);

// 領域の解放
void free_dmatrix(double **a, int row_count, int col_count);

int main(void) {

}

double **dmatrix(int row_count, int col_count) {
    double **a;
    if (( a = malloc( row_count)))
}
