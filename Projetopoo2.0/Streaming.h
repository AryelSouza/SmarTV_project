#ifndef STREAMING_H
#define STREAMING_H
//classe streaming
#include <iostream>
#include <list>
#include <string>
#include "App.h"
#include "Producao.h"
using namespace std;


class Streaming : public App {
  private:
    list<Producao*> producoes;

  public:
    Streaming(string nome, string versao); 
    void operator<<(Producao* producao);
    void operator>>(string nome);
    void operator<<(ostream& out);
    void run();
};

#endif