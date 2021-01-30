#pragma once

class Retangulo {
public:
  Retangulo();
  Retangulo(float altura, float largura);
  Retangulo(float altura, float largura, float posX, float posY, float rotacao = 0);

  float getArea();
  float getPerimetro();

  // Getters e Setters
  float getAltura();
  void setAltura(float altura);

  float getLargura();
  void setLargura(float largura);

  float getPosX();
  void setPosX(float posX);

  float getPosY();
  void setPosY(float posY);

  float getRotacao();
  void setRotacao(float rotacao);

private:
  float altura;
  float largura;
  float posX;
  float posY;
  float rotacao;
};
