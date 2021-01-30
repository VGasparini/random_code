#pragma once

#include <string>
#include <vector>
#include "Pessoa.hpp"
#include "Curso.hpp"

class Disciplina{
	public:
		Disciplina(std::string nomeDisciplina_, Curso &curso_);

		std::string getNome();
		void setNome(std::string novoNome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int novaCarga);

    Pessoa* getProfessor();
    void setProfessor(Pessoa *professor_);

    std::string getNomeProfessor();

    bool adicionarAluno(Pessoa *aluno);
    std::vector<Pessoa *> getVetorAlunos();
    int getNumAlunos();
    bool removerAluno(Pessoa *aluno);
    bool removerAluno(unsigned long long cpfAluno);
    
    void imprimirDados(std::string &cabecalho);
	private:
		std::string nome;
		unsigned short int cargaHoraria;
    Pessoa *professor;
    std::vector<Pessoa *> alunos{50};
    Curso &curso;
};
