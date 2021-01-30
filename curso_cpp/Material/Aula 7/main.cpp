#include <iostream>
#include <string>

#include "Pessoa.hpp"
#include "Disciplina.hpp"

int main()
{
	Pessoa *prof{new Pessoa{"Paulao", 30}};
	Disciplina disciplinaCPP{"C++"};
	disciplinaCPP.setProfessor(prof);

	Pessoa *aluno{new Pessoa{"Gaspa", 23}};
	if (disciplinaCPP.adicionarAluno(aluno))
		std::cout << "Aluno inserido" << std::endl;
	else
		std::cout << "Deu ruim" << std::endl;

	std::cout << "Disciplina " + disciplinaCPP.getNome() << std::endl;
	std::cout << "Professor " + disciplinaCPP.getNomeProfessor() << std::endl;

	Pessoa **alunos = disciplinaCPP.getVetorAlunos();
	for (short int i; i < disciplinaCPP.getNumAlunos(); i++)
	{
		std::cout << "Aluno " << i + 1 << ": " << alunos[i]->getNome() << std::endl;
	}

	return 0;
}
