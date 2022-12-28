//classe serie
#ifndef SERIE_H
#define SERIE_H
#include "Producao.h"

class Serie : public Producao {
  private:
    int numEpisodios;

  public:
    Serie(string nome, int numEpisodios) : Producao(nome), numEpisodios(numEpisodios) {}

    int getNumEpisodios() { return numEpisodios; }

    void play() {
        cout << "Reproduzindo série " << getNome() << " com " << numEpisodios << " episódios" << endl;
        listAtores();
        listDiretores();
    }
};

#endif