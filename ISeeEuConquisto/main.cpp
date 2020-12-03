#include "includes.h"

using namespace std;

#pragma region UserOS

#define WINDOWS 1 // SE O UTILIZADOR ESTIVER A USAR LINUX SUBSTITUIR WINDOWS POR LINUX

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
string username;
int ouro = 0, produtos = 0;
#pragma endregion


void jogo() {

}

void inicio() {

    clear();
    cout << "Bem vindo a aventura, amigo, bem-haja! Vamos comecar?...\n";
    pause();
    cout << "Espera... ainda nem sei o teu nome...";
    pause();
    cout << "Entao? Como te chamas?\n\nInserir Nickname: ";
    cin >> username;
    clear();
    cout << username << "... e isso? Prazer em conhecer-te!";
    pause();
    cout << "Bem, vieste em boa altura, estamos mesmo a precisar de uma maozinha...";
    pause();
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
    cout << "Conheces?";
    pause();
    cout << "Pois... E aqui que tudo comeca... Esta e a tua casa, o DEIS, onde vais passar muitos anos a aprender e descobrir maneiras de expandir o teu territorio!";
    pause();
    cout << "Bem, bora comecar, nao e?";
    
    jogo();
}

void carrega() {

    clear();
    cout << "Teste Carrega";

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
