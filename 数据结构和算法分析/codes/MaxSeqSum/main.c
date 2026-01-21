#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "alg.c"

int main(){
    int n = 100;
    int A[n];
    int maxSum = 0;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 101 - 50; 
    }

    clock_t start, end;
    double cpu_time_used;

    if (n<=1000){
        start = clock(); 
        maxSum = MaxSeqSum1(A, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Alg1: %.6f us\n", cpu_time_used*1e6);
        printf("The maximum subsequence sum is: %d\n", maxSum);
    }

    if (n<=10000){
        start = clock(); 
        maxSum = MaxSeqSum2(A, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Alg2: %.6f us\n", cpu_time_used*1e6);
        printf("The maximum subsequence sum is: %d\n", maxSum);
    }

    start = clock(); 
    maxSum = MaxSeqSum3(A, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Alg3: %.6f us\n", cpu_time_used*1e6);
    printf("The maximum subsequence sum is: %d\n", maxSum);

    start = clock();
    maxSum = MaxSeqSum4(A, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Alg4: %.6f us\n", cpu_time_used*1e6);
    printf("The maximum subsequence sum is: %d\n", maxSum);
    return 0;
}
