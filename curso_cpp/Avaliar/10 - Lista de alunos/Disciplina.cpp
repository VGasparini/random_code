#include "Disciplina.hpp"

#include<iostream>
#include <list>

Disciplina::Disciplina(std::string nome, Curso &curso)
	:nome{nome}, curso{curso} {
		curso.incrementaDisciplina();
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

Pessoa* Disciplina::getProfessor(){
	return this->professor;
}

void Disciplina::setProfessor(Pessoa* professor){
	this->professor = professor;
}

void Disciplina::adicionarAluno(Pessoa* aluno){
	alunos.push_back(aluno);
}
		
bool Disciplina::removerAluno(Pessoa* aluno){
	for(itAlunos = alunos.begin(); itAlunos != alunos.end(); itAlunos++)
		if((*itAlunos)==aluno) //continua até encontrar o aluno
			break;

	if(itAlunos != alunos.end()){//encontrou ou chegou no final da lista?
		delete *itAlunos;//removendo a pessoa da memória
		alunos.erase(itAlunos);//removendo o ponteiro da pessoa removida da lista
	}
	return true;
}



bool Disciplina::removerAluno(unsigned long cpf){
	for(itAlunos = alunos.begin(); itAlunos != alunos.end(); itAlunos++)
		if(((*itAlunos)->getCpf()) == cpf) //continua até encontrar o aluno
			break;

	if(itAlunos != alunos.end()){//encontrou ou chegou no final da lista?
		delete *itAlunos;//removendo a pessoa da memória
		alunos.erase(itAlunos);//removendo o ponteiro da pessoa removida da lista
	}
	return true;
}
	

void Disciplina::mostrarAlunos(){
	for(itAlunos = alunos.begin(); itAlunos != alunos.end(); itAlunos++)//a lista contém ponteiros para pessoas, e não pessoas
		std::cout << (*itAlunos)->getNome() << std::endl;//o itPes é um ponteiro que aponta pra um ponteiro de pessoa!)

	std::cout << std::endl;

}

void Disciplina::imprimeDados(std::string& cabecalho, unsigned int& cargaTotalCurso){
	double pctCurso = (double)cargaHoraria/cargaTotalCurso;
	pctCurso = pctCurso * 100;
	std::cout << cabecalho << std::endl;
	std::cout << "Disciplina: " << this->nome << std::endl;
	std::cout << "Carga: " << this->cargaHoraria << std::endl;
	std::cout << "Percentagem do curso: " << pctCurso << "%" << std::endl;
	std::cout << "Professor: " << this->professor->getNome() << std::endl;
	std::cout << "Curso: " << curso.getNome() << std::endl;

}
