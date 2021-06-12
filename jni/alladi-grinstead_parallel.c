//Constante Producto infinito, con Alladi-Grinstead
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h> 
#include <arm_neon.h>
long double official = 1.75874362795118482469;
int iteration = 100000000;

int main(int argc, char const *argv[]){

    if (argc == 2)
	{
		iteration = atoi(argv[1]);
	}
    printf("Vector size: %d \n", iteration);

    double start_time, run_time;
    omp_set_num_threads(4);
    start_time = omp_get_wtime();
    float32x2_t vectorResult = {1.0,1.0}; 
    long double resultScalar = 1.0;
#pragma omp parallel  
{
#pragma omp single
	printf(" num_threads = %d \n",omp_get_num_threads());

#pragma omp for reduction(*:resultScalar)
        for (int i = 2; i <= iteration/2; i=i+2){
            float32x2_t vectorPartial = {
                powf(1.0+1.0/i, 1.0/i),
                powf(1.0+1.0/(i+1.0), 1.0/(i+1))
            };
            vectorResult = vmul_f32(vectorResult,vectorPartial);
        }
}
        printf("\033[0;34m v[0] %.24f v[1] %.24f \n", vectorResult[0] , vectorResult[1]);
        resultScalar = vectorResult[0]*vectorResult[1];
        
        printf("\033[0;34m %.24Lf \n",resultScalar);
        printf("\033[0;34m Error:  %.5Lf %% \n",(official - resultScalar)*100);
        run_time = omp_get_wtime() - start_time;
        printf("\033[0;34m");
        printf("Alladi-Grinstead Parallel %f seconds\n",run_time);
        printf("\033[0m");
}