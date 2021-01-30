parametrosCompilacao=-Wall #-Wshadow

all: aula10

aula10: main.o Pessoa.o Curso.o Disciplina.o
	g++ -o aula10 main.o Pessoa.o Curso.o Disciplina.o  $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Disciplina.o: Disciplina.hpp Disciplina.cpp
	g++ -c Disciplina.cpp $(parametrosCompilacao)

Curso.o: Curso.hpp Curso.cpp
	g++ -c Curso.cpp $(parametrosCompilacao)

clean:
	rm *.o aula10
