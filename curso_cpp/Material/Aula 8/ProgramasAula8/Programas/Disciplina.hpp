#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"
#include "Curso.hpp"

class Disciplina
{
public:
	Disciplina(std::string nomeDisciplina, Curso &curso);

	std::string getNome();
	void setNome(std::string novoNome);

	int getCargaHoraria();
	void setCargaHoraria(unsigned int novaCarga);

	Pessoa *getProfessor();
	void setProfessor(Pessoa *novoProfessor);

	Curso getCurso();
	void imprimeCurso();

	void imprimeDados(std::string &cabecalho, unsigned int &cargaTotalCurso);

private:
	std::string nome;
	unsigned short int cargaHoraria;
	Curso &curso;
	Pessoa *professor;
};
#endif
