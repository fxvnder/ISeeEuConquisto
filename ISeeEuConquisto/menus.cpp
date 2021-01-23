#include "includes.h"

using namespace std;

void MainMenuASCII() {
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
                      >>> 2018012875              >>> 2018019295

     Vamos comecar a nossa aventura? Ou ja comecaste o grind?
            1 - Novo mundo // 2 - Carrega mundo                        
)";
}

void CasteloASCII() {
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
}

void BemVindoAoISECText() {
    cout << R"(
        
        BEM-VINDO AO ISEC.

        Bem, vejo que e a primeira vez que estas a jogar isto, entao vamos aprender a jogar!

        Tu vais comecar no DEIS, esse e o teu territorio inicial, que a cada jogada que fazes te vai dar:
          >>>  DEIS (Resistencia: 9) => 1 unidade de produtos e 1 de ouro
        Como e obvio, o teu terreno inicial nao te vai dar pontos de vitoria, mas a partir daqui, tu tratas disso!

        A cada jogada que fazes o teu progresso vai ser gravado e podes retomar quando quiseres, se quiseres.

        Como vais querer guardar o nome deste imperio? )";
}

void AjudaPreJogo() {
    cout << R"(
        
        >>> AJUDA <<<

        Bem-vindo ao ISEC. Estes sao os comandos que deves saber para aprender a jogar!

        > COMANDOS PRE-JOGO

        >> CRIA x y = VAI CRIAR UM TERRITORIO DO TIPO x E DA QUANTIDADE y.

        >> LISTA (x) = VAI LISTAR TODOS OS TERRITORIOS DO MUNDO OU UM INDIVIDUAL (x - sensivel a maiusculas)

        >> NICKNAME x = VAI MUDAR O TEU NICKNAME IN-GAME. SO O PODES FAZER ENQUANTO O JOGO NAO COMECAR!

        >> SAIR = ...pois
        
        )";
}


void AjudaPosJogo() {
    cout << R"(
        
        >>> AJUDA <<<

        Bem-vindo ao ISEC. Estes sao os comandos que deves saber para aprender a jogar!

        > COMANDOS POS-JOGO

        >> CONQUISTA x = VAIS TENTAR CONQUISTAR O TERRITORIO x! BOA SORTE!

        >> MAISOURO / MAISPROD = OBTEM +1 DO QUE DESEJA EM TROCA DE -2 DO QUE TEM.

        >> MAISMILITAR = OBTEM +1 UNIDADE MILITAR EM TROCA DE 1 DO COFRE E 1 DE ARMAZEM.

        >> LISTA (x) = VAI LISTAR TODOS OS TERRITORIOS DO MUNDO E DO TEU IMPERIO, OU UM INDIVIDUAL (x).

        >> PASSAR = PASSA O TURNO A FRENTE.
        
        >> SAIR = VAIS SAIR DO JOGO E PERDER O PROGRESSO. JA ES CRESCIDO E SABES O QUE ISSO IMPLICA...
        
        )";
}

void GameONMenu() {
    cout << R"(
      ___ ___ ___ ___         ___   ___              ___        ___                    _    _         
     |_ _/ __| __/ __|  ___  |_ _| / __| ___ ___    | __|  _   / __|___ _ _  __ _ _  _(_)__| |_ ___   
      | |\__ \ _| (__  |___|  | |  \__ \/ -_) -_)_  | _| || | | (__/ _ \ ' \/ _` | || | (_-<  _/ _ \_ 
     |___|___/___\___|       |___| |___/\___\___( ) |___\_,_|  \___\___/_||_\__, |\_,_|_/__/\__\___(_)
                                                |/                             |_|                    
        
        BEM-VINDO AO ISEC.
        
        Ja te contamos as regras, ja criaste os territorios...

        Agora diverte-te e tenta fazer o melhor score! 

        Vais comecar no turno 1, e tens mais 11 pela frente, onde vais poder fazer o que achares melhor para
    seres o melhor izekiano do planeta.
        
        Sera que tens o que e preciso?)";
}

void CasteloTurnos() {
    cout << R"(
[][][] /""\ [][][]
 |::| /DEIS\ |::|
 |[]|_|:JR:|_|[]|
 |::::::__::::::|
 |:::::/||\:::::|
 |:#:::||||::#::|

)";
}