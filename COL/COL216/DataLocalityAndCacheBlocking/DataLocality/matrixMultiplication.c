#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matMultijk(int n, float *A, float *B, float *C)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i + j * n] += A[i + k * n] * B[i + j * n];
            }
        }
    }
}

void matMultikj(int n, float *A, float *B, float *C)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i + j * n] += A[i + k * n] * B[k + j * n];
            }
        }
    }
}
void matMultjik(int n, float *A, float *B, float *C)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i + j * n] += A[i + k * n] * B[k + j * n];
            }
        }
    }
}

void matMultjki(int n, float *A, float *B, float *C)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                C[i + j * n] += A[i + k * n] * B[k + j * n];
            }
        }
    }
}

void matMultkij(int n, float *A, float *B, float *C)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i + j * n] += A[i + k * n] * B[k + j * n];
            }
        }
    }
}

void matMultkji(int n, float *A, float *B, float *C)
{
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                C[i + j * n] += A[i + k * n] * B[k + j * n];
            }
        }
    }
}

int main(int argc, char **argv)
{
    int nmax = 1000, i, n;

    void (*orderings[])(int, float *, float *, float *) = {&matMultijk, &matMultikj, &matMultjik, &matMultjki, &matMultkij, &matMultkji};
    char *names[] = {"ijk", "ikj", "jik", "jki", "kij", "kji"};

    float *A = (float *)malloc(nmax * nmax * sizeof(float));
    float *B = (float *)malloc(nmax * nmax * sizeof(float));
    float *C = (float *)malloc(nmax * nmax * sizeof(float));

    struct timeval start, end;

    if (argv[1])
    {
        for (n = 10; n <= nmax; n = n < nmax && n + 20 > nmax ? nmax : n + 20)
        {
            for (i = 0; i < n * n; i++)
                A[i] = drand48() * 2 - 1;
            for (i = 0; i < n * n; i++)
                B[i] = drand48() * 2 - 1;
            for (i = 0; i < n * n; i++)
                C[i] = drand48() * 2 - 1;

            for (i = 0; i < 6; i++)
            {
                // taking avg of 5 iterations
                double sec_list[5];
                for (int iter = 0; iter < 5; iter++)
                {
                    gettimeofday(&start, NULL);
                    (*orderings[i])(n, A, B, C);
                    gettimeofday(&end, NULL);

                    /* convert time to Gflop/s */
                    double seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
                    sec_list[iter] = seconds;
                }
                double seconds = 0;
                for (int iter = 0; iter < 5; iter++)
                {
                    seconds += sec_list[iter];
                }
                seconds /= 5;
                double Gflops = 2e-9 * n * n * n / seconds;
                printf("%.3f ,", seconds);
            }
            printf("\n");
        }
    }

    free(A);
    free(B);
    free(C);

    printf("\n\n");

    return 0;
}