
//classe producao
#ifndef PRODUCAO_H
#define PRODUCAO_H

#include <string>
#include <list>
#include "Diretor.h"
#include "Ator.h"

class Producao {
protected:
    std::string nome;
    std::list<Diretor*> diretores;
    std::list<Ator*> atores;

public:
    Producao(std::string nome);

    std::string getNome();
    void setNome(std::string nome);

    void addAtor(Ator* ator);
    void removeAtor(std::string nome);

    void addDiretor(Diretor* diretor);
    void removeDiretor(std::string nome);

    void listAtores();
    void listDiretores();
    virtual void play() = 0;
};

#endif