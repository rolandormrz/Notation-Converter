CC=g++
CFLAGS= -std=c++11
INC=
LIB=

all:  converter

converter:  main.o DLDeque.o NotationConverter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^ 

main.cpp:  NotationConverter.hpp

NotationConverter.cpp:  NotationConverterInterface.hpp DLDeque.hpp

clean:
	rm -f *.o converter