#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.hpp"
#include "Retangulo.hpp"
#include "Disciplina.hpp"

int main(int argc, char *argv[]) {
	Pessoa* p1{new Pessoa{"Joao", 20}};
  Curso computacao{"Técnico em Informática", 2002, 3200};

  Disciplina d1{"C++", computacao};
  d1.setProfessor(p1);

  Pessoa *a1{new Pessoa{"Lucas", 22}}, *a2{new Pessoa{"Jaison", 43, 12345678909}};

  d1.adicionarAluno(a1);
  d1.adicionarAluno(a2);

  int numAlunos = d1.getNumAlunos();
  std::vector<Pessoa *> alunos = d1.getVetorAlunos();
  std::cout << "Alunos: " << std::endl;
  for (int i = 0; i < numAlunos; i++) {
    std::cout << alunos[i]->getNome() << std::endl;
  }

  // Antes de deletar, remover da disciplina.
  if (d1.removerAluno(a1)) {
    delete a1;
  } else {
    std::cout << "Algo muito estranho aconteceu, e não foi possível remover uma criança da sua turma usando a referência dela." << std::endl;
  }

  if (d1.removerAluno(a2->getCPF())) {
    delete a2;
  } else {
    std::cout << "Algo muito estranho aconteceu, e não foi possível remover uma criança da sua turma pelo CPF." << std::endl;
  }

  delete p1;

  return 0;
}