#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class ClasseMina : public ClasseTerritorios
{
public:
	// p/ user criar minas
private:

};

void ClasseCastelo2Turnos()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Castelo";
	Territorios.Resistencia = 7;
	Territorios.ProdOuro = 1;
	Territorios.ProdProdutos = 3;
	Territorios.Pontos = 1;
}

void ClasseCastelo()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Castelo";
	Territorios.Resistencia = 7;
	Territorios.ProdOuro = 1;
	Territorios.Pontos = 1;
}