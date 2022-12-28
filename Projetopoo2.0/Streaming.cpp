#include "Streaming.h"

// construtor
Streaming::Streaming(string nome, string versao) : App(nome, versao) {}

// sobrecarga do operador << para adicionar uma produção
void Streaming::operator<<(Producao* producao) {
    producoes.push_back(producao);
}

// sobrecarga do operador >> para remover uma produção
void Streaming::operator>>(string nome) {
    for (auto it = producoes.begin(); it != producoes.end(); it++) {
        if ((*it)->getNome() == nome) {
            producoes.erase(it);
            break;
        }
    }
}

// sobrecarga do operador << para imprimir as produções disponíveis
void Streaming::operator<<(ostream& out) {
    out << "Produções disponíveis:" << endl;
    for (auto p : producoes) {
        out << p->getNome() << endl;
    }
}

// funçao run para executar o app
void Streaming::run() {
    cout << "Selecione uma produção para assistir:" << endl;
    int i = 1;
    for (auto p : producoes) {
        cout << i << " - " << p->getNome() << endl;
        i++;
    }
    cout << "Digite o numero referente a produção que você deseja: ";
    int opcao;
    cin >> opcao;
    auto it = producoes.begin();
    advance(it, opcao-1);
    (*it)->play();
}