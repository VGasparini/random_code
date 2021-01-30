#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso{
    public:
        Curso(std::string nome, unsigned short anoCriacao, unsigned short cargaHorariaMinima);

        std::string getNome();
        void setNome(std::string nome);

        unsigned short getAnoCriacao();
        void setAnoCriacao(unsigned int anoCriacao);

        unsigned short getCargaHorariaMinima();
        void setCargaHorariaMinima(unsigned int cargaHorariaMinima);

        unsigned short getQtdDisciplinas();
        void incrementaDisciplina();

        void imprimeDados(std::string& cabecalho);
    private:
        std::string nome;
        unsigned short anoCriacao;
        unsigned short cargaHorariaMinima;
        unsigned short qtdDisciplinas;
};

#endif
