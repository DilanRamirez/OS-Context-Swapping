read_input: read_input.o write_input.o
	gcc -o read_input read_input.o write_input.o -lm

read_input.o: read_input.c
	gcc -O -Wall -c read_input.c

write_input.o: write_input.c
	gcc -O -Wall -c write_input.c

clean:
	rm -f read_input.o write_input.o hw

