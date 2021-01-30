parametrosCompilacao=-Wall -Wshadow
SRC = main.o Pessoa.o Disciplina.o Curso.o

all: aula8

aula8: $(SRC)
	g++ -o3 -o aula8 $^  $(parametrosCompilacao)

%.o: %.cpp
	g++ -c $^ $(parametrosCompilacao)

run: aula8 clean 
	clear; ./aula8

clean:
	rm *.o
