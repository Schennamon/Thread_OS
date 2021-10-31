#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg{
	char *thread_name;
	char *str;
	int num;
};

void *thread_func(void *arg){
	struct thread_arg targ = *(struct thread_arg*)arg;

	for(int i = 0; i < targ.num; i++){
		fprintf(stderr,  "%s  %s - %d\n\n", targ.thread_name, targ.str, i);
		sleep(1);
	}
	return NULL;
}

int main(){
	pthread_t thread1, thread2, thread3, thread4;
	struct thread_arg thread_arg1;
	struct thread_arg thread_arg2;
	struct thread_arg thread_arg3;
	struct thread_arg thread_arg4;

	thread_arg1.thread_name = "Thread 1";
	thread_arg1.str = "hello from thread1";
	thread_arg1.num = 5;

	thread_arg2.thread_name = "Thread 2";
	thread_arg2.str = "hello from thread2";
	thread_arg2.num = 2;  

	thread_arg3.thread_name = "Thread 3";
	thread_arg3.str = "hello from thread3";
	thread_arg3.num = 6;

	thread_arg4.thread_name = "Thread 4";
	thread_arg4.str = "hello from thread4";
	thread_arg4.num = 1;

	if(pthread_create(&thread1, NULL, &thread_func, &thread_arg1) != 0){
		fprintf(stderr, "Error(thread1)\n");
		return 1;
	}

	if(pthread_create(&thread2, NULL, &thread_func, &thread_arg2) != 0){
		fprintf(stderr, "Error(thread2)\n");
		return 1;
	}

	if(pthread_create(&thread3, NULL, &thread_func, &thread_arg3) != 0){
		fprintf(stderr, "Error(thread3)\n");
		return 1;
	}

	if(pthread_create(&thread4, NULL, &thread_func, &thread_arg4) != 0){
		fprintf(stderr, "Error(thread4)\n");
		return 1;
	}

	while(1);

	return 0;
}