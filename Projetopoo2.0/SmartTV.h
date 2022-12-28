#ifndef SMARTV_H
#define SMARTV_H
//classe smarttv
#include <list>
#include "App.h"
using namespace std;



class SmartTV {
  protected:
    list<App*> aplicativos;
    bool ligada;
    string marca;
    string modelo;
    string so;

  public:
    SmartTV(string marca, string modelo, string so);
    void setMarca(string marca);
    void setSo(string so);
    void ligar();
    void desligar();
    void instalar(App* app);
    void desinstalar(string nome);
    void executar(string nome);
    //função instalar com sobrecarga
    friend void operator<<(SmartTV& tv, App* app){
        if (!tv.ligada) {
            throw runtime_error("A SmartTV está desligada");
        }

        tv.aplicativos.push_back(app);
        cout << "Aplicativo " << app->getNome() << " instalado" << endl;
    }
    //função desinstalar com sobrecarga
    friend istream& operator>>(istream& is, SmartTV& tv){
        // lê o nome do app
        string app;
        is >> app;

        // Encontra o app
        for (auto it = tv.aplicativos.begin(); it != tv.aplicativos.end(); it++) {
            if ((*it)->getNome() == app) {
                tv.aplicativos.erase(it);
                cout << "Aplicativo " << app << " desinstalado" << endl;
                break;
            }
        }

        return is;
    }
};

#endif