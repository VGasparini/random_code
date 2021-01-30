#include "Disciplina.hpp"

Disciplina::Disciplina(std::string nomeDisciplina)
	: nome{nomeDisciplina}
{
}

std::string Disciplina::getNome()
{
	return nome;
}

void Disciplina::setNome(std::string novoNome)
{
	nome = novoNome;
}

int Disciplina::getCargaHoraria()
{
	return cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int novaCarga)
{
	cargaHoraria = novaCarga;
}

void Disciplina::setProfessor(Pessoa *novoProfessor)
{
	professor = novoProfessor;
}

Pessoa *Disciplina::getProfessor()
{
	return professor;
}

std::string Disciplina::getNomeProfessor()
{
	return getProfessor()->getNome();
}

bool Disciplina::adicionarAluno(Pessoa *aluno)
{
	if (getNumAlunos() < 50)
	{
		alunos[getNumAlunos()] = *aluno;
		numAlunos++;
		return true;
	}
	else
	{
		return false;
	}
}

Pessoa **Disciplina::getVetorAlunos()
{
	return &alunos;
}

short int Disciplina::getNumAlunos()
{
	return numAlunos;
}