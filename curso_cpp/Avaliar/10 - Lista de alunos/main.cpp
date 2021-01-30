#include <iostream>
#include <list>

#include "Pessoa.hpp"
#include "Disciplina.hpp"


int main(){

	//disciplina.setProfessor(p1);
	//disciplina.setCargaHoraria(72);
	//std::string cabecalho = "Dados da disciplina";
	//unsigned int cargaHorariaTotal = 3000;
	//disciplina.imprimeDados(cabecalho, cargaHorariaTotal);
	//std::string cabecalho2 = "Dados do curso";
	//c1.imprimeDados(cabecalho2);
	//delete p1;
	
	Curso c1{"BCC", 2020, 3000};
	Disciplina disciplina{"C++", c1};

	Pessoa* p1{new Pessoa{"Joao", 15, 11111111111}};
    Pessoa* p2{new Pessoa{"Maria", 16, 46516085072}};
    Pessoa* p3{new Pessoa{"Pedro", 20, 25537076063}};
    Pessoa* p4{new Pessoa{"Jose", 13, 38657194066}};

	disciplina.adicionarAluno(p1);
    disciplina.adicionarAluno(p2);
    disciplina.adicionarAluno(p3);
    disciplina.adicionarAluno(p4);

    disciplina.mostrarAlunos();

    disciplina.removerAluno(p4); //remove aluno 4

    disciplina.mostrarAlunos();

    disciplina.removerAluno(11111111111); //remove aluno 1 passando o CPF como parametro

    disciplina.mostrarAlunos();

}
