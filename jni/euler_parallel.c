
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <arm_neon.h>
#define REAL_EULER 2.7182818284590452353602874713527
long num_steps = 1000;
double step;

long double factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 8)
    {
        unsigned int result_partial = 1;
        for (int i = 1; i <= n; i++)
        {
            result_partial = result_partial * i;
        }
        printf("factorial: %Lf :  \n", (long double)(result_partial));
        return (long double)result_partial;
    }
    else
    {
        uint32x4_t vr = {1, 1, 1, 1};
        unsigned int reminder = n % 4;
        unsigned int limit = n - reminder;
        for (unsigned int i = 0; i < limit; i = i + 4)
        {
            uint32x4_t vt = {i + 1, i + 2, i + 3, i + 4};
            vr = vmulq_u32(vt, vr);
        }
        if (reminder != 0)
        {
            uint32x4_t vt = {
                limit + 1,
                reminder == 2 ? limit + 2 : 1,
                reminder == 3 ? limit + 3 : 1,
                1};
            vr = vmulq_u32(vt, vr);
        }
        printf("factorial: %Lf :  \n", (long double)(vr[0] * vr[1] * vr[2] * vr[3]));
        return (long double)(vr[0] * vr[1] * vr[2] * vr[3]);
    }
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
    omp_set_num_threads(4);
    start_time = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for reduction(+ \
                          : euler)
        for (i = 0; i < num_steps; i++)
        {

            euler = euler + ((1 / factorial(i)));
            printf("step: %d %Lf \n", i, euler);
        }
    }
    run_time = omp_get_wtime() - start_time;
    printf("\n euler is %Lf in %f seconds and %d threads\n", euler, run_time, omp_get_num_threads());
    char *dataToStore = (char *)malloc(100 * sizeof(char));
    long double error = fabsl((long double)REAL_EULER - euler);
    sprintf(dataToStore, "%ld %Lf %lf %.20Lf \n", num_steps, euler, run_time, error);
    printf(" Error:  %.20Lf \n", error);
}