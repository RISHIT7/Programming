#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void transpose_ij_add(int n, int blocksize, int *dst, int *src)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dst[j + n*i] = src[i + n*j];
}
void transpose_ji_add(int n, int blocksize, int *dst, int *src)
{
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            dst[j + n*i] = src[i + n*j];
}
void transpose_ij_inp(int n, int blocksize, int *src)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            int temp = src[j + n*i];
            src[j + n*i] = src[i + n*j];
            src[i + n*j] = temp;
        }
}
void transpose_ji_inp(int n, int blocksize, int *src)
{
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
        {
            int temp = src[j + n*i];
            src[j + n*i] = src[i + n*j];
            src[i + n*j] = temp;
        }
}

int main(int argc, char **argv)
{
    int n = 5000, i;
    int blocksize = 20; /* to do: find a better block size */

    /* allocate an n*n block of integers for the matrices */
    int *A = (int *)malloc(n * n * sizeof(int));
    int *B = (int *)malloc(n * n * sizeof(int));

    /* initialize A,B to random integers */
    srand48(time(NULL));
    for (i = 0; i < n * n; i++)
        A[i] = lrand48();
    for (i = 0; i < n * n; i++)
        B[i] = lrand48();

    /* measure performance */
    struct timeval start, end;
    double seconds;

    for (int i = 5; i < n; i += 20)
    {
        gettimeofday(&start, NULL);
        transpose_ij_add(i, blocksize, B, A);
        gettimeofday(&end, NULL);

        seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
        printf("%g, ", seconds * 1e3);

        gettimeofday(&start, NULL);
        transpose_ji_add(i, blocksize, B, A);
        gettimeofday(&end, NULL);

        seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
        printf("%g, ", seconds * 1e3);

        gettimeofday(&start, NULL);
        transpose_ij_inp(i, blocksize, A);
        gettimeofday(&end, NULL);

        seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
        printf("%g, ", seconds * 1e3);

        gettimeofday(&start, NULL);
        transpose_ji_inp(i, blocksize, A);
        gettimeofday(&end, NULL);

        seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
        printf("%g, ", seconds * 1e3);

        printf("\n");
    }
    /* release resources */
    free(A);
    free(B);
    return 0;
}
