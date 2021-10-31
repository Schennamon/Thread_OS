#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define A_COUNT 10
#define B_COUNT 15

void *print_b(void *arg){
	int i;

	for(i = 0; i < B_COUNT; i++){
		fprintf(stderr, "B");
		sleep(1);
	}
	fprintf(stderr, "C");
	
	return (void*) i;
}

int main(){
	pthread_t thread;
	int i, pdata;

	if(pthread_create(&thread, NULL, &print_b, NULL) != 0){
		fprintf(stderr, "Error\n");
		return 1;
	}

	for(i = 0; i < A_COUNT; i++){
		fprintf(stderr, "A");
		sleep(1);
	}

	if(pthread_join(thread, (void*) &pdata) != 0){
		fprintf(stderr, "Join error");
		return 1;
	}

	fprintf(stderr, "D\n");
	fprintf(stderr, "%d\n", pdata);

	return 0;
}