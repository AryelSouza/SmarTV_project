//classe time
#ifndef TIME_H
#define TIME_H

#include "App.h"

class Time : public App {
  public:
    Time(string nome, string versao) : App(nome, versao) {}

    void run() {
        time_t now = time(0);
        tm* local = localtime(&now);

        cout << "Data e hora atuais: " << asctime(local) << endl;
    }
};

#endif