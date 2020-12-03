#include "territorios.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class territorios {

    int tamanho;

public:
    territorios(int tamanho) : tamanho(tamanho){
    cout << "Territorio criado..." << endl;
    };

    ~territorios(){
        cout << "Territorio apagado..." << endl;
    }

    string toString(){
        return to_string(tamanho);
    }
};

// PARA ME LEMBRAR
// FAZER FUNCAO GERARNOVOTERRENO(COORDENADA X, COORDENADA Y)
// ONDE O JOGADOR ESTA NA POSICAO - 500, 000 (EXEMPLO)O TERRENO � GERADO NA DIRE�AO QUE O JOGADOR VAI, POR EXEMPLO
// ESQUERDA OESTE GERARNOVOTERRENO(PLAYERX - 500, PLAYERY)
// DIREITA ESTE GERARNOVOTERRENO(PLAYERX + 500, PLAYERY)
// CIMA NORTE GERARNOVOTERRENO(PLAYERX, PLAYERY + 500)
// BAIXO SUL GERARNOVOTERRENO(PLAYERX, PLAYERY - 500)