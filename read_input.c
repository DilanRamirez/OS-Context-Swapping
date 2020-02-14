#include <stdio.h>
#include "write_input.h"

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
