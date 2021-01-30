#include "Disciplina.hpp"
#include <iostream>

Disciplina::Disciplina(std::string nomeDisciplina_, Curso &curso_)
	: nome{nomeDisciplina_}, curso{curso_} {
  for (int i = 0; i < 50; i++) {
    this->alunos[i] = nullptr;
  }
}

std::string Disciplina::getNome(){
	return this->nome;
}

void Disciplina::setNome(std::string nome){
	this->nome = nome;
}

int Disciplina::getCargaHoraria(){
	return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int cargaHoraria){
	this->cargaHoraria = cargaHoraria;
}


Pessoa* Disciplina::getProfessor() {
  return this->professor;
}

void Disciplina::setProfessor(Pessoa *professor) {
  this->professor = professor;
}

std::string Disciplina::getNomeProfessor() {
  return this->professor->getNome();
}

bool Disciplina::adicionarAluno(Pessoa *aluno){
  if (aluno != nullptr) {
    // Aluno informado deve existir
    for (int i = 0; i < 50; i++) {
      // Encontrar se há vaga na turma
      if (this->alunos[i] == nullptr) {
        // Se houver vaga na turma, popular com o novo aluno.
        this->alunos[i] = aluno;
        return true;
      }
    }
  }

  // Se algo der errado.
  return false;
}

std::vector<Pessoa*> Disciplina::getVetorAlunos() {
  return this->alunos;
}

int Disciplina::getNumAlunos() {
  int i = 0;
  for (; i < 50; i++) {
    if (this->alunos[i] == nullptr) break;
  }

  return i;
}

bool Disciplina::removerAluno(Pessoa *aluno) {
  int i = 0;
  bool removido = false;

  if (aluno != nullptr) {
    // Aluno informado deve existir
    for (; i < 50; i++) {
      // Encontrar aluno na turma
      if (this->alunos[i] == aluno) {
        // Remover aluno da lista.
        this->alunos[i] = nullptr;
        removido = true;
        break;
      }
    }

    // Se o aluno for encontrado, então 0 <= i < 50.
    // Mover os seguintes para preencher o vazio criado na turma ;-;
    if (i < 50) {
      for (; i < 49; i++) {
        this->alunos[i] = this->alunos[i+1];
      }
    }
  }

  if (removido) return true;
  return false;
}

bool Disciplina::removerAluno(unsigned long long cpf) {
  int i = 0;
  bool removido = false;

  // Buscar aluno seguindo CPF
  for (; i < 50; i++) {
    if (this->alunos[i] != nullptr) {
      if (this->alunos[i]->getCPF() == cpf) {
        this->alunos[i] = nullptr;
        removido = true;
      }
    }
  }

  // Se o aluno for encontrado, então 0 <= i < 50.
  // Preencher o vazio criado pela remoção do aluno.
  if (i < 50) {
    for (; i < 49; i++) {
      this->alunos[i] = this->alunos[i+1];
    }
  }

  if (removido) return true;
  return false;
}

void Disciplina::imprimirDados(std::string &cabecalho) {
  double pctCurso = (double)(100 * cargaHoraria) / this->curso.getCargaHorariaMinima();
  std::cout << cabecalho << std::endl;
  std::cout << "Disciplina: " << this->nome << std::endl;
  std::cout << "Carga: " << this->cargaHoraria << std::endl;
  std::cout << "Pct do Curso: " << pctCurso << "%" << std::endl;
  std::cout << "Professor: " << this->getNomeProfessor() << std::endl;
}