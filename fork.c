#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

//Function to start timer
double startTime(){
	clock_t start1 = clock();
   	return start1;
}

//function to stop timer.
double endTime(clock_t start1){
   	clock_t end1 = clock();

   	double time_elapsed_in_seconds = (end1 - start1)/(double)CLOCKS_PER_SEC;
   	printf("Total time: %0.12lf\n", time_elapsed_in_seconds);

   	return time_elapsed_in_seconds;
}


/*In the Fork_Function() we will use two pipes to show how the process interrupts
to send a string and concatenate it to another string getting the result RamirezDilan.
By doing it, I will track the time between the communication of the parent process and the child process
to estimate the time it takes to switch between processes. 
*/
double fork_Function(){
	int my_pipe1[2], my_pipe2[2];
	double start, end;
	pid_t cpid, p;
	char name[]="Dilan";
	char lastname[] = "Ramirez";

	printf("Input:%s\n", name);
	//Chech both pipes in case they fail.
	if(pipe(my_pipe1) == -1){
		printf("Pipe1 Failed\n");
	}
	if(pipe(my_pipe2) == -1){
		printf("Pipe2 Failed\n");
	}
	p = fork();

	if(p<0){
		printf("Fork Failed\n");
	}
	//Inside Parent Process
	else if(p > 0){
		char concat_str[100];

		close(my_pipe1[0]); //close the reading end of first "my_pipe[0]""
		write(my_pipe1[1],lastname, strlen(lastname)+1); //write the string of the first pipe"
		close(my_pipe1[1]); //After the child process, parent will close the writing end of second pipe "my_pipe[1]"
		
		start = startTime();
		cpid = wait(NULL);//Wait for child to respond.

		close(my_pipe2[1]); //closing wite of the second pipe
		read(my_pipe2[0], concat_str, 100); //Read string from child
		printf("Concatenated string: %s\n", concat_str); 
		close(my_pipe2[0]);
		

	//Inside Child Process
	}else{ // child proces 
		close (my_pipe1[1]); //Child reads the first string sent by parent process by closing the writing end of my_pipe[1]
		
		// Read a string using first pipe
		char concat_str[100];
		read(my_pipe1[0], concat_str, 100); // concatenate both string and passes the string to parent process
		
		int length = strlen(concat_str);
		for(int i=0; i<strlen(name);i++){
			concat_str[length++] = name[i]; //Concatenate String "Ramirez"
		}
		concat_str[length] = '\0';
		close(my_pipe1[0]);
		close(my_pipe2[0]);

		end = endTime(start);
		write(my_pipe2[1], concat_str, strlen(concat_str)+1); // write string "Ramirez"
		close(my_pipe2[1]); //close the pipe
		
		exit (0);
		return end;
	}	
}

int main(int arcg, char* argv[]){	
	fork_Function();
	

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