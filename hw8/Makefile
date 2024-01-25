CC = g++
FLAGS = -std=c++11 

all:
	$(CC) $(FLAGS) -c libs/huffmanlib.cpp -o obj/huffmanlib.o
	$(CC) $(FLAGS) -c main.cpp -o obj/main.o
	$(CC) $(FLAGS) obj/main.o -o main.elf

clean:
	rm -rf *.elf *.o obj/*.o
	rm output/*.compress output/*.txt output/*.jpg 