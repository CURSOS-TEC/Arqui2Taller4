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
    float *X = malloc(vectorSize * sizeof(float));
    float *Z = malloc(vectorSize * sizeof(float));
    float scalar = 3.5;
    double start_time, run_time;
    start_time = omp_get_wtime();
    for (size_t i = 0; i < vectorSize; i+= 4)
    {
        X[i] = 5.5;
        X[i+1] = 5.5;
        X[i+2] = 5.5;
        X[i+3] = 5.5;
        float32x4_t vx = vld1q_f32(X+i);
        vx = vmulq_n_f32( vx, scalar);


        Y[i] = 6.3;
        Y[i+1] = 6.3;
        Y[i+2] = 6.3;
        Y[i+3] = 6.3;
        float32x4_t vy = vld1q_f32(Y+i);


        //Z[i] = scalar * X[i] + Y[i];
        float32x4_t vz = vaddq_f32(vx,vy);
        vst1q_f32(Z+i,vz);
        /* code */
    }
    run_time = omp_get_wtime() - start_time;
    printf("\033[0;33m");
    printf("SAXPY PARALLEL %f \n",run_time);
    printf("\033[0m");
    return 0;
}
