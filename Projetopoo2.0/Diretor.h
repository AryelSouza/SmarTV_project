//classe diretor

#ifndef DIRETOR_H
#define DIRETOR_H
#include "Pessoa.h"

using namespace std;

class Diretor : public Pessoa {
  private:
    int numProducoes;

  public:
    Diretor(string nome, int numProducoes) : Pessoa(nome), numProducoes(numProducoes) {}

    int getNumProducoes() { return numProducoes; }
    void setNumProducoes(int numProducoes) { this->numProducoes = numProducoes; }
};


#endif