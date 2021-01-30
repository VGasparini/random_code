#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <list>

#include "Pessoa.hpp"
#include "Curso.hpp"

class Disciplina{
	public:
		Disciplina(std::string nome, Curso &curso);

		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);
		
		Pessoa* getProfessor();
		void setProfessor(Pessoa* professor);

		void imprimeDados(std::string& cabecalho, unsigned int& cargaTotalCurso);

		void adicionarAluno(Pessoa* aluno);

		bool removerAluno(Pessoa* aluno);

		bool removerAluno(unsigned long cpf);

		void mostrarAlunos();

	private:
		std::string nome;
		unsigned short int cargaHoraria;
		Curso &curso;
		Pessoa* professor;

		std::list<Pessoa*> alunos;
		std::list<Pessoa*>::iterator itAlunos;
};
#endif
