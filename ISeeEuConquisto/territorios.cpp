#include "territorios.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class territorios {

public:

    string nometerr;
    int res;
    int cprod;
    int couro;
    int pontos;

    class terrInicial{

    public:

        
        terrInicial();
        ~terrInicial();

    };

    /*terrInicial::terrInicial(){

        cout << "Territorio criado..." << endl;
    }

    terrInicial::~terrInicial(){

        cout << "Territorio apagado..." << endl;
    }

    

    territorios(int tamanho) : tamanho(tamanho){
    
    };

    ~territorios(){
        
    }

    string toString(){
        return to_string(tamanho);
    }*/
};


int main1() {

    territorios terrInicial;

    terrInicial.res = 9;
    terrInicial.pontos = 0;
    terrInicial.cprod = 1;
    terrInicial.couro = 1;
    terrInicial.nometerr = "DEIS";
 
    cout << terrInicial.couro << endl;
    cout << terrInicial.nometerr << endl;


    return 0;
}




// PARA ME LEMBRAR
// FAZER FUNCAO GERARNOVOTERRENO(COORDENADA X, COORDENADA Y)
// ONDE O JOGADOR ESTA NA POSICAO - 500, 000 (EXEMPLO)O TERRENO � GERADO NA DIRE�AO QUE O JOGADOR VAI, POR EXEMPLO
// ESQUERDA OESTE GERARNOVOTERRENO(PLAYERX - 500, PLAYERY)
// DIREITA ESTE GERARNOVOTERRENO(PLAYERX + 500, PLAYERY)
// CIMA NORTE GERARNOVOTERRENO(PLAYERX, PLAYERY + 500)
// BAIXO SUL GERARNOVOTERRENO(PLAYERX, PLAYERY - 500)

territorios::terrInicial::terrInicial()
{
}

territorios::terrInicial::~terrInicial()
{
}
