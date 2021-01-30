#pragma once

#include <string>

class Pessoa {
public:
  Pessoa();

  Pessoa(std::string nome_, unsigned short int idade_);

  Pessoa(std::string nome_, unsigned short int idade_, unsigned long long cpf_);

  inline std::string getNome() {
    return this->nome;
  }
  inline void setNome(const std::string nome_) {
    this->nome = nome_;
  }

  inline unsigned short int getIdade() {
    return (unsigned short int)this->idade;
  }
  inline void setIdade(const unsigned short int idade_) {
    this->idade = (uint8_t)idade_;
  }

  inline unsigned long long getCPF() {
    return (unsigned long long)this->cpf;
  }
  inline void setCPF(const unsigned long long cpf_) {
    this->cpf = (uint64_t)cpf_;
  }

private:
  std::string nome;
  uint8_t idade;
  uint64_t cpf;
  
  bool validarCPF(unsigned long long cpf_);
};

