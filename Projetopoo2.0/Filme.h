//classe filme
#ifndef FILME_H
#define FILME_H
#include "Producao.h"

class Filme : public Producao {
  private:
    int duracao;

  public:
    Filme(string nome, int duracao) : Producao(nome), duracao(duracao) {}

    int getDuracao() { return duracao; }

    void play() {
        cout << "Reproduzindo filme " << getNome() << " com duração de " << duracao << " minutos" << endl;
        listAtores();
        listDiretores();
    }
};

#endif