//classe ator

#ifndef ATOR_H
#define ATOR_H
#include "Pessoa.h"

using namespace std;

class Ator : public Pessoa {
  private:
    int tempoCarreira;

  public:
    Ator(string nome, int tempoCarreira) : Pessoa(nome), tempoCarreira(tempoCarreira) {}

    int getTempoCarreira() { return tempoCarreira; }
    void setTempoCarreira(int tempoCarreira) { this->tempoCarreira = tempoCarreira; }
};

#endif