#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <arm_neon.h>
int vectorSize = 100000000;
int main(int argc, char const *argv[])
{
    
	if (argc == 2)
	{
		vectorSize = atoi(argv[1]);
	}
    printf("Vector size: %d \n", vectorSize);

    /* code */
    float *Y = malloc(vectorSize * sizeof(float));
    float32x2_t vector = vcreate_f32(10);
    float *X = malloc(vectorSize * sizeof(float));
    float *Z = malloc(vectorSize * sizeof(float));
    float scalar = 3.5;
    double start_time, run_time;
    start_time = omp_get_wtime();
    for (size_t i = 0; i < vectorSize; i++)
    {
        X[i] = 5.5;
        Y[i] = 6.3;
        Z[i] = scalar*X[i]+ Y[i];  
        /* code */
    }
    run_time = omp_get_wtime() - start_time;
    printf("SAXPY %f \n",run_time);
    return 0;
}
