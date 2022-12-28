//classe pessoa

#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Pessoa {
  protected:
    string nome;

  public:
    Pessoa(string nome) : nome(nome) {}

    string getNome() { return nome; }
    void setNome(string nome) { this->nome = nome; }
};




#endif