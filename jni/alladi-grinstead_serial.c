//Constante Producto infinito, con Alladi-Grinstead
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h> 
long double official = 1.75874362795118482469;
int iteration = 100000000;

int main(int argc, char const *argv[]){

    if (argc == 2)
	{
		iteration = atoi(argv[1]);
	}
    printf("Vector size: %d \n", iteration);

    double start_time, run_time;
    start_time = omp_get_wtime();
    long double result = 1.0;    

	printf(" num_threads = %d \n",omp_get_num_threads());


    for (int i = 2; i < iteration; i++){
        long double partial = powf(1+1/(long double)i, 1/(long double)i);
        result = result * partial;
    }

    printf("\033[0;34m %.30Lf \n",result);
    printf("\033[0;34m Error:  %.5Lf %%  \n",(official - result)*100);
    run_time = omp_get_wtime() - start_time;
    printf("\033[0;34m");
    printf("Alladi-Grinstead %f seconds\n",run_time);
    printf("\033[0m");
}