#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include <malloc.h>
#include <time.h>

void *any_func(void *arg){
	int a = *(int*)arg;
	int *res = malloc(sizeof(int));
	a++;
	*res = a;
	return (void*) res;
}

int main(void)
{
	pthread_t thread;
	int *pdata;
	int parg = 2007;

	if(pthread_create(&thread, NULL, &any_func, &parg) != 0){
		fprintf(stderr, "Error\n");
		return 1;
	}

	pthread_join(thread, (void**) &pdata);
	printf("%d\n", *pdata);
	free(pdata);

	return 0;
}

/*void* roll_dice(){
	int value = (rand() % 6 + 2);
	int * result = malloc(sizeof(int));
	*result = value;

	return (void*) result;
}

int main()
{
	int* res;
	srand(time(NULL));
	pthread_t th;

	if(pthread_create(&th, NULL, &roll_dice, NULL) != 0){
		return 1;
	}

	if(pthread_join(th, (void**) &res) != 0){
		return 2;
	}

	printf("Result: %d\n", *res);

	return 0;
}*/