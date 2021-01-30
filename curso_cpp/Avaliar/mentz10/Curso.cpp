#include "Curso.hpp"


Curso::Curso(std::string nomeCurso, unsigned int anoCriacao, unsigned int cargaHorariaMinima)
  : nomeCurso{nomeCurso}, anoCriacao{anoCriacao}, cargaHorariaMinima{cargaHorariaMinima} {
}

std::string Curso::getNomeCurso() {
  return this->nomeCurso;
}

unsigned int Curso::getAnoCriacao() {
  return this->anoCriacao;
}

unsigned int Curso::getCargaHorariaMinima() {
  return this->cargaHorariaMinima;
}