#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg{
	int num;
	int second_num;
};

void *any_func(void *arg){
	int num = *(int*)arg;
	for(int i = 1; i <= num; i++){
		fprintf(stderr, "Child Thread. Iteration: %d\n", i);
		sleep(1);
	}

	return NULL;
}

void *rand_num_func(void *arg){
	struct thread_arg targ = *(struct thread_arg*)arg;
	int temp;

	for(int i = 0; i < targ.num; i++){
		temp = rand() % 10;

		if(temp != targ.second_num){
			fprintf(stderr, "%d\n", temp);
			sleep(1);
		} else{
			fprintf(stderr, "Thread2 is over\n");
			pthread_exit(NULL);
		}
	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t thread1, thread2;
	struct thread_arg arg;
	int num = 10;

	arg.num = 15;
	arg.second_num = 5;

	if(pthread_create(&thread1, NULL, &any_func, &num) != 0){
		fprintf(stderr, "Error(thread1)\n");
		return 1;
	}

	if(pthread_create(&thread2, NULL, &rand_num_func, &arg) != 0){
		fprintf(stderr, "Error(thread2)\n");
		return 1;
	}

	if(pthread_join(thread1, NULL) != 0){
		fprintf(stderr, "Join 1 - error");
		return 1;
	}

	if(pthread_join(thread2, NULL) != 0){
		fprintf(stderr, "Join 2 - error");
		return 1;
	}

	fprintf(stderr, "Main Thread is over\n");

	while(1);

	return 0;
}