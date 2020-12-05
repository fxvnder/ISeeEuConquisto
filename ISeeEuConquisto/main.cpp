#include "includes.h"
#include "comando.h"

using namespace std;
using namespace Comandos;

#pragma region UserOS

// PERGUNTAR AO UTILIZADOR QUAL O SISTEMA OPERATIVO ESTA A USAR, ASSIM SENDO O DEFINE VAI PASSAR A SER AUTOMÁTICO

#define WINDOWS 1 // SE O UTILIZADOR ESTIVER A USAR LINUX SUBSTITUIR WINDOWS POR LINUX
//#define LINUX 1 // IDEM

void clear() { // LIMPA O ECRÃ SEM O CONIO.H \\ CLRSCR()
#ifdef WINDOWS
    system("cls");
#endif
#ifdef LINUX
    system("clear");
#endif
}

void syspause() { // SYS.PAUSE = PRESS ANY KEY TO CONTINUE
#ifdef WINDOWS
    system("pause");
#endif
#ifdef LINUX
    system("read");
#endif
}

void pause() { // PAUSA EM PRINTS
    cin.ignore();
    cin.get();
}

#pragma endregion

#pragma region VarsGlobais
string username, nomeficheiro;
int ouro = 0, produtos = 0;
class_comando ClasseComandos;
#pragma endregion


void jogo(bool PrimeiraVez) {

    if (PrimeiraVez == true) {
        clear();
        cout << "Bem, vejo que e a primeira vez que estas a jogar isto, entao vamos aprender a jogar";
        cout << "\nTu vais comecar no DEIS, e o teu territorio inicial, que a cada jogada que fazes te vai dar";
        cout << "\n\nComo queres guardar o nome deste imperio?\n";
        cin >> nomeficheiro;
        ClasseComandos.grava(nomeficheiro);
    }
    else
    {
        cout << "Bem vindo de volta, " << username;
    }

}

void inicio() {

    clear();
    cout << "Bem vindo a aventura, amigo, bem-haja! Vamos comecar?...\n";
    cout << "\n...espera... ainda nem sei o teu nome...";
    pause();
    cout << "\nBem... Entao? Como te chamas?";
    cout << "\n\nInserir Nickname: ";
    cin >> username;
    clear();
    cout << username << "... e isso? Prazer em conhecer-te!";
    pause();
    cout << "Bem, vieste em boa altura, estamos mesmo a precisar de uma maozinha...";
    pause();
    clear();
    cout << R"(
   /\                                                        /\
  |  |                                                      |  |
 /----\                                                    /----\
[______]                                                  [______]
 |    |         _____                        _____         |    |
 |[]  |        [     ]                      [     ]        |  []|
 |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |
 |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |
 |             |     |/'    DEIS--ISEC    '\|     |             |
  \  []        |     |    /'    ||    '\    |     |        []  /
   |      []   |     |   |o     ||     o|   |     |  []       |
   |           |  _  |   |     _||_     |   |  _  |           |
   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |
   |           |     |   |     (||)     |   |     |           |
   |           |     |   |      ||      |   |     |           |
 /''           |     |   |o     ||     o|   |     |           ''\
[_____________[_______]--'------''------'--[_______]_____________]
)";
    pause();
    cout << "\nConheces?";
    pause();
    cout << "\nPois... E aqui que tudo comeca... \nEsta e a tua casa, o DEIS\nOnde vais passar muitos anos a aprender e descobrir maneiras de expandir o teu territorio!";
    pause();
    cout << "\nEm cada jogo vais ter 2 anos, e com isto 12 turnos, onde podes fazer as mais variadas coisas para expandir o territorio e conseguires uma pontuacao superior a dos teus demais.";
    cout << "\nTodos nos gostamos de jogos competitivos, certo? vieste parar ao certo!\n\nMas agora... e a serio.";
    pause();
    jogo(true);
}

void carrega() {
    bool sucesso = false;

    clear();
    do
    {
        cout << "Qual e o nome do imperio que queres carregar? ";
        cin >> nomeficheiro;
        cout << "\n";
        ClasseComandos.carrega(nomeficheiro);
        sucesso = true;
    } while (sucesso == false);


    jogo(false);
}

int main() {
    int operacao;
    bool start = false;

    cout << R"(
           %%%%%%%%%%%%                                                         
       %%%%%%%%%%%%%%%%%%%%                                                 
     %%%%%%%%%%%%%%%%%%%%%%%%                                                   
   #%%%%%%%%%%%    %%%%%%%%%%%        %%%%  %%%%%%%%%%   %%%%%%%%%   %%%%%%%%%  
  .%%%%%%%%%          %%%%%%%%%       %%%%  %%%%}       %%%____%%%% %%%%     
  %%%%%%%%%            %%%%%%%%%      %%%%      {%%%%%  %%%         %%%%     
  %%%%%%%%%            %%%%%%%%%      %%%%  #%%%%%%%%%   %%%%%%%%%   %%%%%%%%%. 
  %%%%%%%%%            %%%%%%%%%                                                
  %%%%%%%%%            %%%%%%%%%                                               
  %%%%%%%%%            %%%%%%%%%      ISEC
  %%%%%%%%%            %%%%%%%%%                           I See, Eu Conquisto!

     by the greatest devs Joao 'FXVNDER' Oliveira and Ze 'EdEquinox' Marques

     Vamos comecar a nossa aventura? Ou ja comecaste o grind?
            1 - Novo mundo // 2 - Carrega mundo                        
)";
    while (start == false) {
        cout << "               >> ";
        cin >> operacao;
        if (operacao == 1) {
            start = true;
            inicio();
        } else if (operacao == 2) {
            start = true;
            carrega();
        } else cout << "           Acho que te enganaste, amigo... Mas eu dou-te outra chance! \n";
    }

    return 0;
}
