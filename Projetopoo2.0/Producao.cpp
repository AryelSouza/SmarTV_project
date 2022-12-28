#include "Producao.h"

using namespace std;
//construtor
Producao::Producao(string nome) : nome(nome) {}

//getters e setters
string Producao::getNome() { return nome; }
void Producao::setNome(string nome) { this->nome = nome; }

//metodos add e remove ator e diretor
void Producao::addAtor(Ator* ator) { atores.push_back(ator); }
void Producao::removeAtor(string nome) {
    for (auto it = atores.begin(); it != atores.end(); it++) {
        if ((*it)->getNome() == nome) {
            atores.erase(it);
            break;
        }
    }
}

void Producao::addDiretor(Diretor* diretor) { diretores.push_back(diretor); }
void Producao::removeDiretor(string nome) {
    for (auto it = diretores.begin(); it != diretores.end(); it++) {
        if ((*it)->getNome() == nome) {
            diretores.erase(it);
            break;
        }
    }
}

//metodos para listar atores e diretores
void Producao::listAtores() {
    cout << "Atores:" << endl;
    for (auto a : atores) {
        cout << a->getNome() << " - " << a->getTempoCarreira() << " anos de carreira" << endl;
    }
}

void Producao::listDiretores() {
    cout << "Diretores:" << endl;
    for (auto d : diretores) {
        cout << d->getNome() << " - " << d->getNumProducoes() << " produções" << endl;
    }
}