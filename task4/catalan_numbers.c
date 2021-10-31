#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<malloc.h>

long func(int n, int *data){
	int k;
  	long s = 0;

  	if (n < 2){
    	return 1;
  	}

  	for (k = 0; k < n; k ++){
    	s += data[k] * data[n - 1 - k];
  	}

  	return s;
}

void *catalan_numbers(void *arg){
	int i;
	int n = *(int*)arg;
	int *data = (int*)malloc(n*sizeof(int));

	for (i = 0; i < n; i ++){
    	data[i] = func(i, data);
    }

    return (void*) data;
}

int is_prime(int num){
    if ((num * num) % 24 == 1){
        return 0;
    }

 	return 1;
}

void *simple_numbers(void *arg){
	int n = *(int*)arg;
	int *data = (int*)malloc(sizeof(int));
	int size = 1;

	for(int i = 1; i <= n; i++){
		if(is_prime(i) == 0 || i == 2 || i == 3){
			size++;
			data = (int*)realloc(data, size * sizeof(int));
			data[size - 2] = i;
		}
	}
	
	return (void*) data;
}

int main(int argc, char **argv){
	pthread_t thread1, thread2;
	int *pcatalan, *psimple;
	int arg1 = atoi(argv[1]);
	int arg2 = atoi(argv[2]);
	int i;

	if(pthread_create(&thread1, NULL, &catalan_numbers, &arg1) != 0){
		fprintf(stderr, "Error\n");
		return 1;
	}

	if(pthread_create(&thread2, NULL, &simple_numbers, &arg2) != 0){
		fprintf(stderr, "Error\n");
		return 1;
	}

	if(pthread_join(thread1, (void**) &pcatalan) != 0){
		fprintf(stderr, "Error\n");
	}

	if(pthread_join(thread2, (void**) &psimple) != 0){
		fprintf(stderr, "Error\n");
	}


	for(int i = 0; i < arg1; i++){
		printf("%d\n", pcatalan[i]);
	}
	printf("\n\n");

	i = 0;
	while(psimple[i] != 0){
		printf("%d\n", psimple[i]);
		i++;
	}

	free(pcatalan);
	free(psimple);

	return 0;
}
