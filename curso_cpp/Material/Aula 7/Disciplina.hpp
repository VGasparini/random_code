#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include "Pessoa.hpp"

#define MAXN 50

class Disciplina
{
public:
	Disciplina(std::string nomeDisciplina);

	std::string getNome();
	void setNome(std::string novoNome);

	int getCargaHoraria();
	void setCargaHoraria(unsigned int novaCarga);
	Pessoa *getProfessor();
	void setProfessor(Pessoa *novoProfessor);
	std::string getNomeProfessor();
	bool adicionarAluno(Pessoa *aluno);
	Pessoa **getVetorAlunos();
	short int getNumAlunos();

private:
	std::string nome;
	unsigned short int cargaHoraria;
	Pessoa *professor;
	Pessoa *alunos{new Pessoa[MAXN]};
	short int numAlunos = 0;
};
#endif
