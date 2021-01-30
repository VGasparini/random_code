#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso
{
public:
    Curso(std::string nomeCurso, unsigned short anoCriacao, unsigned short cargaHorariaMinima);

    std::string getNome();

    unsigned short getCargaHoraria();
    void setCargaHoraria(unsigned short novaCarga);

    unsigned short getAnoCriacao();

    void imprimeDados();

private:
    std::string nome;
    unsigned short anoCriacao;
    unsigned short cargaHorariaMinima;
};
#endif
