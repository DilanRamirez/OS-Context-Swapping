//Program that reads and imput using gets() and then print it calling another function from write_input.h

#include <stdio.h>
#include "write_input.h"

//Function that reads and input using gets()
char *read_input(char input[50]){
	printf("Enter a String: ");
	gets(input);
	return input;
}

int main(int argc, char *argv[]){
	char input[50];

	read_input(input);
	print_input(input);

	return 0;
}
