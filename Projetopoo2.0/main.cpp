#include "SmartTV.h"
#include "App.h"
#include "Diretor.h"
#include "Ator.h"
#include "Producao.h"
#include "Filme.h"
#include "Serie.h"
#include "Time.h"
#include "Streaming.h"


int main() {
    //instancia SmartTV
    SmartTV tv("Samsung", "QLED", "Android");
    //lista de streamings
    list<App*> streaming;
    //ligando a tv para que possa ser instalado os apps
    tv.ligar();
        
    //criando streamings
    Streaming* Netflix = new Streaming("Netflix", "1.0");
    Streaming* HBO = new Streaming("HBO", "1.7");
    Streaming* Disney = new Streaming("Disney", "1.0");
    Streaming* Amazon = new Streaming("Amazon", "1.0");
    Streaming* Hulu = new Streaming("Hulu", "1.0");
    Streaming* Globoplay = new Streaming("Globoplay", "1.0");

    //adicionando na lista streaming
    streaming.push_back(Netflix);
    streaming.push_back(HBO);
    streaming.push_back(Disney);
    streaming.push_back(Amazon);

    //criando o time
    Time* time = new Time("Time", "1.0");
    //instalar
    tv.instalar(Netflix);
    tv.instalar(HBO);
    tv.instalar(time);
    tv.instalar(Disney);
    tv.instalar(Globoplay);
    tv << Amazon;
    tv << Hulu;
    //desinstalar
    tv.desinstalar("Hulu");
    tv.desinstalar("Globoplay");
    
    
    //filmes
    Filme* f1 = new Filme("Vingadores: Ultimato", 182);
    Filme* f2 = new Filme("Toy Story 4", 100);
    Filme* f3 = new Filme("O Rei Leão", 120);
    Filme* f4 = new Filme("O Irlandês", 200);
    Filme* f5 = new Filme("1917", 120);
    Filme* f6 = new Filme("Os Vingadores", 200);
    Filme* f7 = new Filme("O Exterminador do Futuro", 120);
    Filme* f8 = new Filme("O Poderoso Chefão", 200);
    Filme* f9 = new Filme("O Poderoso Chefão 2", 120);
    Filme* f10 = new Filme("O Poderoso Chefão 3", 200);

    //series
    Serie* s1 = new Serie("The Walking Dead", 100);
    Serie* s2 = new Serie("Game of Thrones", 80);
    Serie* s3 = new Serie("Breaking Bad", 50);
    Serie* s4 = new Serie("Stranger Things", 30);
    Serie* s5 = new Serie("The Big Bang Theory", 120);
    Serie* s6 = new Serie("Friends", 100);
    Serie* s7 = new Serie("How I Met Your Mother", 90);
    Serie* s8 = new Serie("The Office", 90);
    Serie* s9 = new Serie("The Simpsons", 30);
    Serie* s10 = new Serie("The Flash", 15);

    
    
    //atores
        Ator a("Leonardo DiCaprio", 30);
        f1->addAtor(&a);
        Ator b("Brad Pitt", 40);
        f1->addAtor(&b);
        Ator c("Tom Hanks", 50);
        f2->addAtor(&c);
        Ator d("Tim Allen", 30);
        f2->addAtor(&d);
        Ator e("Donald Glover", 40);
        f3->addAtor(&e);
        Ator f("Billy Eichner", 20);
        f3->addAtor(&f);
        Ator g("Robert De Niro", 40);
        f4->addAtor(&g);
        Ator h("Al Pacino", 60);
        f4->addAtor(&h);
        Ator i("Joe Pesci", 60);
        f5->addAtor(&i);
        Ator j("Robert Downey Jr.", 22);
        f5->addAtor(&j);
        Ator k("Chris Evans", 23);
        f6->addAtor(&k);
        Ator l("Chris Hemsworth", 19); 
        f6->addAtor(&l);
        Ator m("Arnold Schwarzenegger", 50);
        f10->addAtor(&m);
        Ator n("Linda Hamilton", 39);
        f8->addAtor(&n);
        Ator o("Marlon Brando", 60);
        f9->addAtor(&o);

    //diretores
        Diretor d1("Anthony Russo", 30);
        f1->addDiretor(&d1);
        Diretor d2("Joe Russo", 40);
        f1->addDiretor(&d2);
        Diretor d3("Josh Cooley", 50);
        f2->addDiretor(&d3);
        Diretor d4("Jon Favreau", 60);
        f2->addDiretor(&d4);
        Diretor d5("Tarantino", 38);
        f7->addDiretor(&d5);
        Diretor d6("Sam Mendes", 44);
        f3->addDiretor(&d6);
        Diretor d7("Martin Scorsese", 58);
        f4->addDiretor(&d7);
        Diretor d8("Padilla", 10);
        f5->addDiretor(&d8);
        Diretor d9("Tim Burton", 50);
        f6->addDiretor(&d9);
        Diretor d10("James Cameron", 50);
        f8->addDiretor(&d10);
        Diretor d11("Francis Ford Coppola", 30);
        f9->addDiretor(&d11);
        Diretor d12("Christopher Nolan", 40);
        f10->addDiretor(&d12);

            
    //coloquei os filmes e series nos streaming
    //netflix
    *Netflix << f1;
    *Netflix << f2;
    *Netflix << s1;
    *Netflix << s2;
    *Netflix << f9;
    //hbo
    *HBO << f3;
    *HBO << f4;
    *HBO << s3;
    *HBO << s7;
    *HBO << f10;
    //disney
    *Disney << f5;
    *Disney << f6;
    *Disney << s4;
    *Disney << s8;
    //amazon
    *Amazon << f7;
    *Amazon << f8;
    *Amazon << s5;
    *Amazon << s6;
    *Amazon << s9;
    *Amazon << s10;




    //interação com o usuário
    int tst;

    int opcao;
    //label para voltar
    voltar:
    tst = 0;
    do {
        cout << "\033[40;34m1 - Ligar\33[0m" << endl;
        cout << "\033[40;34m2 - Desligar\33[0m" << endl;
        cout << "\033[40;34m3 - Executar aplicativo\33[0m" << endl;
        cout << "\033[40;34m4 - Sair\33[0m" << endl;
        cout << "\033[40;35mDigite o numero referente a opção que você deseja: \33[0m";
        cin >> opcao;
        system("clear");
        //verifica se a opção é válida
        if (opcao>4 || opcao<1) {
            cin.clear();
            cin.ignore();
            system("clear");
            cout << "\033[40;31mOPÇÃO INVÁLIDA\033[0m\n" << endl;
            goto voltar;
        }
        cin.ignore();
        switch (opcao) {
            case 1:
                system("clear");
                tv.ligar();
                break;
            case 2:
                
                tv.desligar();
                while (tst != 1)
                {
                    cout << "\033[1;35mA tv foi desligada,deseja ligar novamente? 1 - Sim 2 - Não\033[0m" << endl;
                    cin >> tst;
                    if (tst == 1)
                    {   system("clear");
                        tv.ligar();
                        goto voltar;
                    }
                    else if (tst == 2)
                    {
                        cout << "\033[1;33mObrigado por usar a TV!\033[0m\n" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "\033[1;31mOPÇÃO INVÁLIDA\033[0m\n" << endl;
                    }
                }
                
                
                
                break;
            case 3: {
                //exibe os apps disponiveis
                 
                cout << "Lista de Aplicativos: " << endl;
                for (auto app : streaming) {
                    cout << app->getNome() << endl;
                    
                }
                //exibe o time
                cout << time->getNome() << endl;
                
                
                string nome;
                
                cout << "\033[40;35mDigite o nome do aplicativo que você deseja(ou digite 0 para voltar):\33[0m";
                //getline que a primeira letra sempre é maiuscula
                getline(cin, nome);
                nome[0] = toupper(nome[0]);
                system("clear");
                
                
                if (nome == "0")
                {
                    system("clear");
                    goto voltar;
                }
                tv.executar(nome);
                
            }

        }
    } while (opcao != 4);
    cout << "\033[1;33mObrigado por usar a TV!\033[0m\n" << endl;
    
//fim do programa
    return 0;
}