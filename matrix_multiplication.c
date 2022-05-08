#include <stdio.h>

// takes pointer to first element of matrix and its order
void print_matrix(int*, int, int);

// takes pointer to first element of two input matrix and
// one result matrix and order of result matrix and
// column/row of first/second input matrix
void matmul(int*, int*, int*, int, int, int);

// function used to fill matrix from user input
void fill_matrix(int*, int, int);

int main() {
    int m, n, n_, t; // orders of two input matrix m x n, n_ x t
    printf("Enter the order of first matrix\n>");
    scanf("%d%d", &m, &n);
    // initialize the first input matrix of order (m x n)
    int A[m][n];
    // fill the matrix A with user input;
    fill_matrix(A[0], m, n);
    printf("first matrix: \n");
    print_matrix(A[0], m, n);

    // get order of 2nd matrix
    printf("Enter the order of second matrix\n>");
    scanf("%d%d", &n_, &t);
    while(n != n_) {
        printf("The matrix of order (%d, %d) can't be multiplied with the matrix of order (%d, %d)\n", m, n, n_, t);
        printf("enter the order of second matrix again\n>");
        scanf("%d%d", &n_, &t);
    }
    //initialize second matrix of order (n_=n, t)
    int B[n_][t];
    // initialize result matrix;
    int res[m][t];
    // fill matrix B with user input
    fill_matrix(B[0], n_, t);
    printf("second matrix: \n");
    print_matrix(B[0], n_, t);

    // multiply
    matmul(A[0], B[0], res[0], m, t, n);
    printf("matrix product: \n");
    print_matrix(res[0], m, t);

    return 0;
}


void fill_matrix(int* mat, int m, int n) {
    for(int j=0; j<m; j++) {
        int i = 0;
        printf("Enter %dth row: \n>", j+1);
        while(i<n && scanf("%d", mat + j*n + i)) {
            i++;
        }
    }
}

void print_matrix(int* mat, int m, int n) {
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            printf("%d ", *(mat + j*n + i));
        }
        printf("\n");
    }
}


void matmul(int* A, int* B, int* res, int m, int t, int n) {
    for(int j=0; j<m; j++) {
        for(int i=0; i<t; i++) {
            int sum = 0;
            for(int k=0; k<n; k++) {
                sum += *(A + j*n + k) * *(B + k*t + i);
                // printf("A_curr_elem: %d\tB_curr_elem: %d\n", *(A + j*n + k), *(B + k*t + i));
                // printf("index: %d, %d\nsum: %d\n", j+1, i+1, sum);
                // getchar();
            }
            *(res + j*t + i) = sum;
        }
    }
}