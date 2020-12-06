#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class ClasseDuna : public ClasseTerritorios
{
public:
	// p/ user criar dunas
private:

};

void ClasseDuna()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Duna";
	Territorios.Resistencia = 4;
	Territorios.ProdProdutos = 1;
	Territorios.Pontos = 1;
}