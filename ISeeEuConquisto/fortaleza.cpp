#include "fortaleza.h"
#include "territorios.h"
#include "includes.h"

using namespace std;
using namespace TerritoriosNS;

vector<ClasseTerritorios> Mundo;

void CriaFortaleza(int id, int ntipo) {
    for (int i = 0; i < ntipo; i++)
    {
        Mundo.push_back(ClasseTerritorios());
        Mundo[id].Tipo = "Fortaleza";
        Mundo[id].IDTerr = id;
        Mundo[id].NomeTerritorio = "Fortaleza" + to_string(i + 1);
        Mundo[id].Resistencia = 8;
        Mundo[id].ProdOuro = 0;
        Mundo[id].ProdProdutos = 0;
        Mundo[id].Pontos = 1;
        cout << "Foi criado " << Mundo[id].NomeTerritorio << endl;
    }
};



