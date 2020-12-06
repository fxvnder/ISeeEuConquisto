#include "territorios.h"
#include "includes.h"
#include <vector>
#include <memory>
#include <string>


using namespace std;
using namespace TerritoriosNS;


class ClassePlanicie : public ClasseTerritorios
{
public:
	// p/ user criar planicie
private:

};

void ClassePlanicieValores1Ano()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Planicie";
	Territorios.Resistencia = 5;
	Territorios.ProdProdutos = 1;
	Territorios.ProdOuro = 1;
	Territorios.Pontos = 1;
}

void ClassePlanicieValores2Ano()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Planicie";
	Territorios.Resistencia = 5;
	Territorios.ProdProdutos = 2;
	Territorios.ProdOuro = 1;
	Territorios.Pontos = 1;
}