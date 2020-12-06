#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class ClasseMontanha : public ClasseTerritorios
{
public:
	// p/ user criar montanhas
private:

};

void ClasseMontanhaValores2TurnosInic()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Montanha";
	Territorios.Resistencia = 6;
	Territorios.Pontos = 1;
}

void ClasseMontanhaValores()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Montanha";
	Territorios.Resistencia = 6;
	Territorios.ProdProdutos = 1;
	Territorios.Pontos = 1;
}
