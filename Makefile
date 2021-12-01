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

casillero_transitable.o: casillero_transitable.cpp casillero_transitable.h
	$(CC) $(FLAGS) casillero_transitable.o

casillero_construible.o: casillero_construible.cpp casillero_construible.h
	$(CC) $(FLAGS) casillero_construible.o

casillero_inaccesible.o: casillero_inaccesible.cpp casillero_inaccesible.h
	$(CC) $(FLAGS) casillero_inaccesible.o

casillero.o: casillero.cpp casillero.h
	$(CC) $(FLAGS) casillero.o

mapa.o: mapa.cpp mapa.h
	$(CC) $(FLAGS) mapa.o


Edificio.o: Edificio.cpp Edificio.h
	$(CC) $(FLAGS) Edificio.o

Inicio_juego.o: Inicio_juego.cpp Inicio_juego.h
	$(CC) $(FLAGS) Inicio_juego.o

Interaccion_usuario.o: Interaccion_usuario.cpp Interaccion_usuario.h
	$(CC) $(FLAGS) Interaccion_usuario.o

Jugador.o: Jugador.cpp Jugador.h
	$(CC) $(FLAGS) Jugador.o

Material.o: Material.cpp Material.h
	$(CC) $(FLAGS) material.o


Mensajes_de_error.o: Mensajes_de_error.cpp Mensajes_de_error.h
	$(CC) $(FLAGS) Mensajes_de_error.o

Menu_consola.o: Menu_consola.cpp Menu_consola.h
	$(CC) $(FLAGS) Menu_consola.o

Opcion_comprar_bombas.o: Opcion_comprar_bombas.cpp Opcion_comprar_bombas.h
	$(CC) $(FLAGS) Opcion_comprar_bombas.o

Primer_menu.o: Primer_menu.cpp Primer_menu.h
	$(CC) $(FLAGS) Primer_menu.o

Segundo_menu.o: Segundo_menu.cpp Segundo_menu.h
	$(CC) $(FLAGS) Segundo_menu.o


main.o: main.cpp 
	$(CC) $(FLAGS) main.o

andypolis: main.cpp casillero_transitable.cpp casillero_construible.cpp casillero_inaccesible.cpp casillero.cpp mapa.cpp Edificio.cpp Inicio_juego.cpp Interaccion_usuario.cpp Jugador.cpp Material.cpp Mensajes_de_error.cpp Menu_consola.cpp Opcion_comprar_bombas.cpp Primer_menu.cpp Segundo_menu.cpp
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	@echo "$(GREEN)Limpiando ...$(NORMAL)"
	rm -vf *.o $(PROGRAM)
	@echo "$(GREEN)Listo!$(NORMAL)"

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis
