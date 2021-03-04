#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define VALMAX 32

int main (void){
	int i;
	printf("%d coeurs disponibles\n",omp_get_num_procs());
	for(i=0;i<VALMAX;i++){
		if (i%2==0) //si i divisible par 2
			printf("pour i=%d, resultat pair, trouve par %d\n",i,omp_get_thread_num());
	}
	return 0;
}

