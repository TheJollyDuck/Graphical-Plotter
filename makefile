output: main.o graph.o
	gcc -o release/output *.o -Wall -Wextra -lm

main.o: main.c graph.c graph.h
	gcc -c main.c -Wall -Wextra

graph.o: graph.c graph.h
	gcc -c graph.c -Wall -Wextra