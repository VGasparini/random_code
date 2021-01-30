#include "Curso.hpp"

#include <iostream>

Curso::Curso(std::string nome, unsigned short anoCriacao, unsigned short cargaHorariaMinima)
    :nome{nome}, anoCriacao{anoCriacao}, cargaHorariaMinima{cargaHorariaMinima}, qtdDisciplinas{0} {
}

std::string Curso::getNome(){
    return nome;
}

void Curso::setNome(std::string nome){
    this->nome = nome;
}

unsigned short Curso::getAnoCriacao(){
    return anoCriacao;
}

void Curso::setAnoCriacao(unsigned int anoCriacao){
    this->anoCriacao = (unsigned short)anoCriacao;
}

unsigned short Curso::getCargaHorariaMinima(){
    return cargaHorariaMinima;
}

void Curso::setCargaHorariaMinima(unsigned int cargaHorariaMinima){
    this->cargaHorariaMinima = (unsigned short)cargaHorariaMinima;
}

unsigned short Curso::getQtdDisciplinas(){
    return qtdDisciplinas;
}

void Curso::incrementaDisciplina(){
    qtdDisciplinas++;
}

void Curso::imprimeDados(std::string& cabecalho){
	std::cout << cabecalho << std::endl;
	std::cout << "Curso: " << nome << std::endl;
    std::cout << "Ano de criacao: " << anoCriacao << std::endl;
	std::cout << "Carga Horaria Minima: " << cargaHorariaMinima << std::endl;
    std::cout << "Quantidade de Disicplinas: " << qtdDisciplinas << std::endl;
    std::cout << std::endl;
}
