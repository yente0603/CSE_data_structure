CC = g++
FLAGS = -std=c++11 

all:
	$(CC) $(FLAGS) -c libs/huffmanlib.cpp -o libs/huffmanlib.o
	$(CC) $(FLAGS) -c main.cpp -o libs/main.o
	$(CC) $(FLAGS) libs/main.o -o main.elf

clean:
	rm -rf *.elf *.o libs/*.o
	rm output/*.compress output/*.txt output/*.jpg 