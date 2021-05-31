
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#define REAL_EULER 2.7182818284590452353602874713527
long num_steps = 1000;
double step;

long double factorial(int n)
{
    long double result = 1.0L;
    if (n == 0)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        num_steps = atoi(argv[1]);
    }
    int i;
    long double euler = 0.0L;
    double start_time, run_time;
    omp_set_num_threads(1);
    start_time = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for reduction(+ \
                          : euler)
        for (i = 0; i < num_steps; i++)
            euler = euler + (1 / factorial(i));
    }
    run_time = omp_get_wtime() - start_time;
    printf("\n euler is %Lf in %f seconds and %d threads\n", euler, run_time, omp_get_num_threads());
    char *dataToStore = (char *)malloc(100 * sizeof(char));
    long double error = fabsl((long double)REAL_EULER - euler);
    sprintf(dataToStore, "%ld %Lf %lf %.20Lf \n", num_steps, euler, run_time, error);
    printf(" Error:  %.20Lf \n", error);
}