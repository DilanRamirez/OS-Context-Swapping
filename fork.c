#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>

double gettingTime(){
	clock_t start1 = clock();
   	clock_t end1 = clock();

   	clock_t start2 = clock();
   	clock_t end2 = clock();

   	double time_elapsed_in_seconds1 = (end1 - start1)/(double)CLOCKS_PER_SEC;
   	double time_elapsed_in_seconds2 = (end2 - start2)/(double)CLOCKS_PER_SEC;

   	//printf("time1: %lf\n", time_elapsed_in_seconds1);
   	//printf("time2: %lf\n", time_elapsed_in_seconds2);

   	double Subtract = time_elapsed_in_seconds1 - time_elapsed_in_seconds2;
   	printf("Subtract: %lf\n", Subtract);

   	return Subtract;
}

void fork_Function(){
	int my_pipe[2], p;
	pid_t cpid;

	pipe(my_pipe);
	p = fork();

	printf("Fork: %d\n\n", p);
	if(p > 0){
		close(my_pipe[0]);
		write(my_pipe[1],"Some string from parent", 24);
		//fflush(my_pipe[1]);
		close(my_pipe[1]);
		cpid = wait(NULL);
		printf("Parent pid = %d\n", getpid()); 
    	printf("Child pid = %d\n", cpid); 
		printf("My_pipe if: %d\n", my_pipe[1]);

	}else{ // child proces 
		close (my_pipe[1]);
		char input_str[100];
		read(my_pipe[0], input_str, 100);
		close(my_pipe[0]);
		printf("My_pipe else: %d\n", my_pipe[0]);
		exit (0);
	}	
}

int main(int arcg, char* argv[]){
	double t, t2, avg2, avg, time1, time2, time3, time4, time5;
	//fork_Function();
	time1 = gettingTime();
	time2 = gettingTime();
	time3 = gettingTime();
	time4 = gettingTime();
	time5 = gettingTime();

	avg = (time1 + time2 + time3 + time4 + time5)/5;
	printf("Avg: %lf\n", avg);

	/*
	printf("----------FOR LOOP----------\n");
	for(int i=0;i<5;i++){
		t = gettingTime();
		t2 = t2+t;
		//printf("for time: %lf\n", t2);
	}
	printf("t2: %lf\n", t2);
	avg2 = t2/5;

	printf("Avg2: %lf\n", avg2);
	*/

	return 0;
}