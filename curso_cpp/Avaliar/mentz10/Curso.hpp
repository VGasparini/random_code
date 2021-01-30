#pragma once

#include <string>

class Curso {
public:
  Curso(std::string nomeCurso, unsigned int anoCriacao, unsigned int cargaHorariaMinima);
  
  std::string getNomeCurso();
  unsigned int getAnoCriacao();
  unsigned int getCargaHorariaMinima();

private:
  std::string nomeCurso;
  unsigned int anoCriacao;
  unsigned int cargaHorariaMinima;
};