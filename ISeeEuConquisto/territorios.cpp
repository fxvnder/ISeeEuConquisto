#include "territorios.h"
#include "mundo.h"
#include "comando.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;


#pragma region comentários

// PARA ME LEMBRAR
// FAZER FUNCAO GERARNOVOTERRENO(COORDENADA X, COORDENADA Y)
// ONDE O JOGADOR ESTA NA POSICAO - 500, 000 (EXEMPLO)O TERRENO � GERADO NA DIRE�AO QUE O JOGADOR VAI, POR EXEMPLO
// ESQUERDA OESTE GERARNOVOTERRENO(PLAYERX - 500, PLAYERY)
// DIREITA ESTE GERARNOVOTERRENO(PLAYERX + 500, PLAYERY)
// CIMA NORTE GERARNOVOTERRENO(PLAYERX, PLAYERY + 500)
// BAIXO SUL GERARNOVOTERRENO(PLAYERX, PLAYERY - 500)

// ^^ NAO E PRECISO

//TerritoriosNS::ClasseTerritorios::ClasseTerritorios()
//{
//
//}
//
//TerritoriosNS::ClasseVetores::ClasseVetores()
//{
//}
//
//

#pragma endregion


string ClasseTerritorios::GetNomeTerr() { return NomeTerritorio; }
string ClasseTerritorios::GetTipoTerr() { return Tipo; }
int ClasseTerritorios::GetIDTerr() { return IDTerr; }
int ClasseTerritorios::GetResistencia() { return Resistencia; }
int ClasseTerritorios::GetProdProdutos() { return ProdProdutos; }
int ClasseTerritorios::GetProdOuro() { return ProdOuro; }
int ClasseTerritorios::GetPontos() { return Pontos; }
void ClasseTerritorios::SetNomeTerr(string NomeTerr) { NomeTerritorio = NomeTerr; }
void ClasseTerritorios::SetTipoTerr(string TipoTerr) { Tipo = TipoTerr; }
void ClasseTerritorios::SetIDTerr(int NovoID) { IDTerr = NovoID; }
void ClasseTerritorios::SetResistencia(int NovaRes) { Resistencia = NovaRes; }
void ClasseTerritorios::SetProdP(int NovaPP) { ProdProdutos = NovaPP; }
void ClasseTerritorios::SetProdO(int NovaPO) { ProdOuro = NovaPO; }
void ClasseTerritorios::SetPontos(int NovaPontos) { Pontos = NovaPontos; }

int ClasseVetores::GetTamanhoVetor() { return vetorsize; };
void ClasseVetores::SetTamanhoVetor(int NovoTamanho) { vetorsize = NovoTamanho; };

void ClasseVetores::AddClasseTerritorios(const ClasseTerritorios& NovaClasseTerritorios) {
    Mundo.push_back(NovaClasseTerritorios);
}

inline ClasseTerritorios& ClasseVetores::GetClasseTerritorios(vector<ClasseTerritorios>::size_type NMundo) {
    return Mundo[NMundo];
}
