Lab1: read_input.o write_input.o 
	gcc -o Lab1 read_input.o write_input.o -lm

read_input.o: read_input.c
	gcc -O -Wall -c read_input.c

write_input.o: write_input.c
	gcc -O -Wall -c write_input.c

clean:
	rm -f read_input.o write_input.o Lab1.o

