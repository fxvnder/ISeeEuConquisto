#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;


void inicio() {

    cout << "Teste Inicio";

}

void carrega() {

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
