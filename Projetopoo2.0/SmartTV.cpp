#include "SmartTV.h"

//construtor
SmartTV::SmartTV(string marca, string modelo, string so) : marca(marca), modelo(modelo), so(so) {
        ligada = false;
    }

//setters
void SmartTV::setMarca(string marca) { this->marca = marca; }
void SmartTV::setSo(string so) { this->so = so; }

int tst=0;
//ligar e desligar
void SmartTV::ligar() {
        
        ligada = true;
        cout << "\033[40;34mSmarTV ligada\33[0m" << endl;
        if (tst==1){
        //abre o arquivo txt e carrega as informações da tv
        ifstream arquivo;
        arquivo.open("tv.txt");
        string linha;
        while (getline(arquivo, linha)) {
            cout << linha << endl;
        }
        arquivo.close();
        }
        //modifica o valor de tst global para 1
        tst=1;
    }

void SmartTV::desligar() {
        ligada = false;
        //cria arquivo txt que armazena as informações da tv
        ofstream arquivo;
        arquivo.open("tv.txt");
        arquivo << "Aplicativos instalados:"  << endl;
        for (auto it = aplicativos.begin(); it != aplicativos.end(); it++) {
            arquivo << (*it)->getNome() << endl;
        }
        arquivo << "informações da tv: " << endl;
        arquivo << "ligada: " << ligada << endl;
        arquivo << "marca: " << marca << endl;
        arquivo << "so: " << so << endl;
        arquivo.close();

        //limpa o terminal
        system("clear");
    }
        


//instalar e desinstalar
void SmartTV::instalar(App* app) {
        if (!ligada) {
            throw runtime_error("A SmartTV está desligada");
        }

        aplicativos.push_back(app);
        cout << "Aplicativo " << app->getNome() << " instalado" << endl;
    }

void SmartTV::desinstalar(string nome) {
        if (!ligada) {
            throw runtime_error("A SmartTV está desligada");
        }

        for (auto it = aplicativos.begin(); it != aplicativos.end(); it++) {
            if ((*it)->getNome() == nome) {
                aplicativos.erase(it);
                cout << "Aplicativo " << nome << " desinstalado" << endl;
                break;
            }
        }
    }
//executa os apps
void SmartTV::executar(string nome) {
        if (!ligada) {
            throw runtime_error("A SmartTV está desligada");
        }

        for (auto app : aplicativos) {
            if (app->getNome() == nome) {
                system("clear");
                app->run();
                break;
            }
        }
    };