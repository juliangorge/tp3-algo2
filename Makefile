PROGRAM=TP3
CC := g++
FLAGS := -Wall -Werror -Wconversion -pedantic -std=c++11
LDLFLAGS=-lm
GREEN= \e[92m
NORMAL= \e[0m

all:
	@echo "$(GREEN)Compilando ...$(NORMAL)"
	$(MAKE) andypolis
	@echo "$(GREEN)Terminó$(NORMAL)"

material.o: material.cpp material.h enlistar_materiales.h
	$(CC) $(FLAGS) material.o
	
enlistar_materiales.o: enlistar_materiales.cpp enlistar_materiales.h material.h
	$(CC) $(FLAGS) enlistar_materiales.o

main.o: main.cpp material.h enlistar_materiales.h
	$(CC) $(FLAGS) main.o

andypolis: main.cpp material.cpp enlistar_materiales.cpp
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	@echo "$(GREEN)Limpiando ...$(NORMAL)"
	rm -vf *.o $(PROGRAM)
	@echo "$(GREEN)Listo!$(NORMAL)"

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis
