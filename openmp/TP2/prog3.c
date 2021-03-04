#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>

#define VALINIT 100000000 //1 milliard
#define NBTOURS 500

int  main (void){

	int ncores,div;
	long int i,j;    
	double start, end, time;
	ncores = omp_get_num_procs(); 
	printf("%d coeurs disponibles\n",ncores);
	start=omp_get_wtime();
	for(i=VALINIT;i<VALINIT+NBTOURS;i++){
		div = 1;
		for(j=2;j<i;j++){ //de 2 à i exclu
			if (i%j==0) //si j divise i
				div = 0;}
		if(div) 
			printf("nombre premier : %ld detecte par : %d\n", i, omp_get_thread_num());
	}
	end=omp_get_wtime();
	time=(end-start);
	printf ("temps d'execution : %lg \n",time);
	
	return 0;
}
