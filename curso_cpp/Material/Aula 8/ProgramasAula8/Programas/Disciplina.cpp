#include "Disciplina.hpp"

#include <iostream>

Disciplina::Disciplina(std::string nomeDisciplina, Curso &curso)
	: nome{nomeDisciplina}, curso{curso}
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

Pessoa *Disciplina::getProfessor()
{
	return professor;
}

void Disciplina::setProfessor(Pessoa *novoProfessor)
{
	professor = novoProfessor;
}

void Disciplina::imprimeCurso()
{
	curso.imprimeDados();
}

Curso Disciplina::getCurso()
{
	return curso;
}

void Disciplina::imprimeDados(std::string &cabecalho, unsigned int &cargaTotalCurso)
{
	double pctCurso = (double)cargaHoraria / cargaTotalCurso;
	pctCurso = pctCurso * 100;
	std::cout << cabecalho << std::endl;
	std::cout << "Disciplina: " << nome << std::endl;
	std::cout << "Carga horaria: " << cargaHoraria << std::endl;
	std::cout << "Percentagem do conclusão: " << pctCurso << "%" << std::endl;
	std::cout << "Professor: " << professor->getNome() << std::endl;
	std::cout << "Curso: " << curso.getNome() << std::endl;
	imprimeCurso();
}
