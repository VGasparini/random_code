#include "Curso.hpp"

#include <iostream>

Curso::Curso(std::string nomeCurso, unsigned short anoCriacao, unsigned short cargaHorariaMinima)
    : nome{nomeCurso}, anoCriacao{anoCriacao}, cargaHorariaMinima{cargaHorariaMinima}
{
}

std::string Curso::getNome()
{
    return nome;
}

unsigned short Curso::getAnoCriacao()
{
    return anoCriacao;
}

void Curso::setCargaHoraria(unsigned short novaCarga)
{
    cargaHorariaMinima = novaCarga;
}

unsigned short Curso::getCargaHoraria()
{
    return cargaHorariaMinima;
}

void Curso::imprimeDados()
{
    std::cout << std::endl
              << "--== Dados do curso ==--" << std::endl;
    std::cout << "Curso: " << getNome() << std::endl;
    std::cout << "Ano de criação: " << getAnoCriacao() << std::endl;
    std::cout << "Carga horária: " << getCargaHoraria() << std::endl;
}
