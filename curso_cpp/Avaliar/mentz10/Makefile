CFLAGS=-Wall #-Wshadow
LFLAGS=-lm
CC=g++
TARGET=main

all: $(TARGET)

$(TARGET): main.o Pessoa.o Retangulo.o Disciplina.o Curso.o
	g++ -o $@ $^ $(LFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

clean: 
	rm *.o $(TARGET)
