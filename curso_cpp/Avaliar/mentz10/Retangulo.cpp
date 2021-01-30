#include "Retangulo.hpp"

#include <iostream>

Retangulo::Retangulo() : altura{0}, largura{0}, posX{0}, posY{0}, rotacao{0} {
  // std::cout << "c1" << std::endl;
  // Vazio, tudo feito por lista de inicialização de membros
}

Retangulo::Retangulo(float altura, float largura) : Retangulo() {
  // std::cout << "c2" << std::endl;
  this->altura = altura;
  this->largura = largura;
}

Retangulo::Retangulo(float altura, float largura, float posX, float posY, float rotacao) : Retangulo(altura, largura) {
  // std::cout << "c3" << std::endl;
  this->posX = posX;
  this->posY = posY;
  this->rotacao = rotacao;
}


float Retangulo::getArea() {
  return this->altura * this->largura;
}

float Retangulo::getPerimetro() {
  return 2 * (this->altura + this->largura);
}

// Getters e Setters

float Retangulo::getPosX() {
  return this->posX;
}

void Retangulo::setPosX(float posX) {
  this->posX = posX;
}

float Retangulo::getPosY() {
  return this->posY;
}

void Retangulo::setPosY(float posY) {
  this->posY = posY;
}

float Retangulo::getAltura() {
  return this->altura;
}

void Retangulo::setAltura(float altura) {
  this->altura = altura;
}

float Retangulo::getLargura() {
  return this->largura;
}

void Retangulo::setLargura(float largura) {
  this->largura = largura;
}

float Retangulo::getRotacao() {
  return this->rotacao;
}

void Retangulo::setRotacao(float rotacao) {
  this->rotacao = rotacao;
}