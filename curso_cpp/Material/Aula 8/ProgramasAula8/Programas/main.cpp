#include <iostream>
#include <string>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"

int main()
{
	Curso curso{"BCC", 1902, 3000};

	Pessoa *p1{new Pessoa{"Paulera", 20}};
	Disciplina disciplina{"C++", curso};
	disciplina.setProfessor(p1);
	disciplina.setCargaHoraria(72);

	std::string cabecalhoDisciplina = "--== Dados da disciplina ==--";
	unsigned int cargaHorariaTotal = curso.getCargaHoraria() / 5;
	disciplina.imprimeDados(cabecalhoDisciplina, cargaHorariaTotal);

	delete p1;

	// Descomente aqui para dar xabu. Isso fara com que o curso não exista mais
	// portanto não haverá mais referência dentro da disciplina

	// delete curso;
	// disciplina.imprimeDados(cabecalhoDisciplina, cargaHorariaTotal);

	return 0;
}
