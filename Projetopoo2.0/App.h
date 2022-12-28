//classe app
#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class App {
  protected:
    string nome;
    string versao;
  public:
    App(string nome, string versao) : nome(nome), versao(versao) {}

    string getNome() { return nome; }
    string getVersao() { return versao; }

    void setNome(string nome) { this->nome = nome; }
    void setVersao(string versao) { this->versao = versao; }

    virtual void run() = 0;
};

#endif

