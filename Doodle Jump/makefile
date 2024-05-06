CC := g++ -std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: doodleJump.out

doodleJump.out: main.o enemy.o game.o platform.o sequence.o doodle.o spring.o rsdl.o
	$(CC) main.o rsdl.o enemy.o game.o platform.o doodle.o sequence.o spring.o $(CCFLAGS) -o doodleJemp.out

main.o: game.hpp main.cpp
	$(CC) -c main.cpp -o main.o

enemy.o: enemy.hpp enemy.cpp
	$(CC) -c enemy.cpp -o enemy.o

game.o: game.hpp game.cpp
	$(CC) -c game.cpp -o game.o

doodle.o:
	$(CC) -c doodle.cpp -o doodle.o

platform.o: platform.hpp platform.cpp
	$(CC) -c platform.cpp -o platform.o

spring.o: spring.hpp spring.cpp
	$(CC) -c spring.cpp -o spring.o

sequence.o: sequence.hpp sequence.cpp
	$(CC) -c sequence.cpp -o sequence.o

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o

