#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa() {
  // std::cout << "Construtor 1" << std::endl;
}

Pessoa::Pessoa(std::string nome, unsigned short int idade) : nome{nome}, idade{(uint8_t)idade}, cpf{0} {
  // std::cout << "Construtor 2" << std::endl;
}

Pessoa::Pessoa(std::string nome, unsigned short int idade, unsigned long long cpf) : Pessoa(nome, idade) {
  if (validarCPF(cpf)) {
    this->cpf = cpf;
  } else {
    this->cpf = 0L;
  }
  // std::cout << "Construtor 3" << std::endl;
}

bool Pessoa::validarCPF(unsigned long long cpf) {
  int soma1 = 0, soma2 = 0;
  unsigned short ver1, ver2;

  // Verificar combinações aceitas pelo algoritmo mas inválidas
  if ((cpf % 11111111111) == 0) return 0;

  // Prosseguir com o algoritmo de somar e multiplicar os dígitos
  soma1 = ((cpf / 10000000000) % 10) * 10;
  soma1 += ((cpf / 1000000000) % 10) * 9;
  soma1 += ((cpf / 100000000) % 10) * 8;
  soma1 += ((cpf / 10000000) % 10) * 7;
  soma1 += ((cpf / 1000000) % 10) * 6;
  soma1 += ((cpf / 100000) % 10) * 5;
  soma1 += ((cpf / 10000) % 10) * 4;
  soma1 += ((cpf / 1000) % 10) * 3;
  soma1 += ((cpf / 100) % 10) * 2;
  soma1 = (soma1 % 11);
  soma1 = (soma1 < 2) ? 0 : (11 - soma1);

  soma2 = ((cpf / 10000000000) % 10) * 11;
  soma2 += ((cpf / 1000000000) % 10) * 10;
  soma2 += ((cpf / 100000000) % 10) * 9;
  soma2 += ((cpf / 10000000) % 10) * 8;
  soma2 += ((cpf / 1000000) % 10) * 7;
  soma2 += ((cpf / 100000) % 10) * 6;
  soma2 += ((cpf / 10000) % 10) * 5;
  soma2 += ((cpf / 1000) % 10) * 4;
  soma2 += ((cpf / 100) % 10) * 3;
  soma2 += ((cpf / 10) % 10) * 2;
  soma2 = (soma2 % 11);
  soma2 = (soma2 < 2) ? 0 : (11 - soma2);

  // Separar dígitos verificadores
  ver1 = (cpf / 10) % 10;
  ver2 = cpf % 10;

  // Comparar dígitos verificadores
  if ((soma1 != ver1) || (soma2 != ver2)) return 0;

  return 1;
}
