#pragma region includes e namespaces

// Lista de includes basicos para o funcionamento do programa
#include "includes.h"
// Comandos
#include "comando.h"
// Territorios
#include "territorios.h"
#include "imperio.h"
// Territorios Individuais
//#include "castelo.h"
#include "duna.h"
//#include "fortaleza.h"
//#include "mina.h"
//#include "montanha.h"
//#include "planicie.h"
#include "terrinicial.h"
// Tecnologia
#include "tecnologias.h"

using namespace std;
#pragma endregion

#pragma region UserOS

// vai detetar o OS do utilizador

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
#define WINDOWS 1
#elif defined(__APPLE__) || defined(TARGET_OS_MAC) || defined(__linux__) || defined(__unix__)
#define LINUX 1
#else
#error "PC da NASA?"
#endif

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

// COMENTARIOS COM IDEIAS ANTIGAS:

// PERGUNTAR AO UTILIZADOR QUAL O SISTEMA OPERATIVO ESTA A USAR, ASSIM SENDO TIRA-SE O DEFINE E VAI PASSAR A SER AUTOMÁTICO

// ^^ DONE.

//#define WINDOWS 1 // SE O UTILIZADOR ESTIVER A USAR LINUX SUBSTITUIR WINDOWS POR LINUX
//#define LINUX 1 // IDEM

// ^^ JÁ NÃO É NECESSÁRIO.

#pragma endregion

#pragma region VariaveisEncapsuladas

namespace VariaveisImportantes
{
    string username, nomeficheiro;
}

#pragma endregion

#pragma region Funcoes

void pause() { // PAUSA EM PRINTS
    cin.ignore();
    cin.get();
}

void SeparaPalavras(string operacoes)
{
    vector<string> VectorComandos;
    ClasseComandos ClasseComandosMain;
    string PalavraSeparada;
    stringstream StrStream(operacoes);

    while (StrStream >> PalavraSeparada) {
        VectorComandos.push_back(PalavraSeparada);
    }

    for (unsigned int i = 0; i < VectorComandos.size(); i++) {
        cout << VectorComandos[i] << endl;
    }

    if (VectorComandos[0] == "cria")
    {
        //DEPOIS MUDAR OS FICHEIROS PARA FUNCAO INDIVIDUAL
        stringstream Tamanho(VectorComandos[2]);
        int SeguraInt = 0;
        Tamanho >> SeguraInt;
        ClasseComandosMain.CriaTerreno(VectorComandos[1], SeguraInt);
        ofstream SaveFile;
        SaveFile.open(VariaveisImportantes::nomeficheiro + ".save");
        SaveFile << VectorComandos[0] << " " << VectorComandos[1] << " " << VectorComandos[2] << endl;
        SaveFile.close();
    }
    else if (VectorComandos[0] == "conquista")
    {
        stringstream Tamanho(VectorComandos[1]);
        int SeguraInt = 0;
        Tamanho >> SeguraInt;
        ClasseComandosMain.conquista(VectorComandos[1]);
    }
}

#pragma endregion

void jogo(bool PrimeiraVez) {
    ClasseComandos ClasseComandosMain;
    string operacao;
    string StringIndividual;
    vector<ClasseTerritorios> Mundo;

    if (PrimeiraVez == true) {
        clear();
        cout << R"(
        
        BEM-VINDO AO ISEC.

        Bem, vejo que e a primeira vez que estas a jogar isto, entao vamos aprender a jogar!

        Tu vais comecar no DEIS, esse e o teu territorio inicial, que a cada jogada que fazes te vai dar:
          >>>  DEIS (Resistencia: 9) => 1 unidade de produtos e 1 de ouro
        Como e obvio, o teu terreno inicial nao te vai dar pontos de vitoria, mas a partir daqui, tu tratas disso!

        A cada jogada que fazes o teu progresso vai ser gravado e podes retomar quando quiseres, se quiseres.

        Como vais querer guardar o nome deste imperio? )";
            
        getline(cin, VariaveisImportantes::nomeficheiro);

            // if (nomeficheiro.find(' ') || nomeficheiro.find('ç') || nomeficheiro.find('á') || nomeficheiro.find('?'))
            // cout << "\nO ficheiro nao pode ter espacos ou simbolos no nome!" << endl;
        
            //cout << RemoverEspacos(nomeficheiro);

        cout << VariaveisImportantes::nomeficheiro;
        ClasseComandosMain.grava(VariaveisImportantes::nomeficheiro, VariaveisImportantes::username);
        cout << "\nParabens, " << VariaveisImportantes::username << "! Vamos agora comecar a jogar! Para sair escreva sair" << endl;
        do
        {
            cout << "Insira um comando aqui: ";

            getline(cin, operacao);

            SeparaPalavras(operacao);

        } while (operacao != "sair");

    }
    else
    {
        cout << "Bem vindo de volta, " << VariaveisImportantes::username;
            do
            {
                cout << "\nInsira um comando aqui: ";

                getline(cin, operacao);

                SeparaPalavras(operacao);

            } while (operacao != "sair");
    }

}

void inicio() {

    clear();
    cout << "Bem vindo a aventura, amigo, bem-haja! Vamos comecar?...\n";
    cout << "\n...espera la... ainda nem sei o teu nome!...";
    cout << "\n\nEntao? Como te chamas?";
    cout << "\n\nInserir Nickname: ";
    cin.ignore(1000, '\n');
    getline(cin, VariaveisImportantes::username);
    cout << "\n" << VariaveisImportantes::username << "... e isso? Prazer em conhecer-te!";
    cout << "\nBem, vieste em boa altura, estamos mesmo a precisar de uma maozinha aqui... Junta-te a nos!";
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
    cout << "\nConheces?" << endl;
    cout << "\nPois... E aqui que tudo comeca... \nEsta e a tua casa, o DEIS\nOnde vais passar muitos anos a aprender e descobrir maneiras de expandir o teu territorio!";
    cout << "\nEm cada jogo vais ter 2 anos, e com isto 12 turnos, onde podes fazer as mais variadas coisas para expandir o territorio e conseguires uma pontuacao superior a dos teus demais.";
    cout << "\nTodos nos gostamos de jogos competitivos, certo? vieste parar ao certo!";
    pause();
    jogo(true);
}

void carrega() {
    bool sucesso = false;
    ClasseComandos ClasseComandosMain;

    clear();
    do
    {
        cout << "Qual e o nome do imperio que queres carregar? ";
        cin.ignore(1000, '\n');
        getline(cin, VariaveisImportantes::nomeficheiro);
        cout << "\n";
        ClasseComandosMain.CarregaFicheiro(VariaveisImportantes::nomeficheiro);
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
