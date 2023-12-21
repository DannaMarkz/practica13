CC := g++
CFLAGS := -std=c++11

all: racionales

racionales: racional.o
	$(CC) $(CFLAGS) racional.o -o racionales

racional.o: racional.cc racional.h
	$(CC) $(CFLAGS) -c racional.cc

operaciones.o: operaciones.cc racional.h
	$(CC) $(CFLAGS) -c operaciones.cc

clean:
	rm -f *.o racionales
