#pragma once

#include "includes.h"
#include "planicie.h"

using namespace std;

namespace TerritoriosNS
{
	class ClasseTerritorios {

	public:

		string NomeTerritorio = "";
		int Resistencia = 0;
		int ProdProdutos = 0;
		int ProdOuro = 0;
		int Pontos = 0;

	};
	class TerritorioInicial
	{
	public:
		TerritorioInicial();

	private:
	};

	TerritorioInicial::TerritorioInicial()
	{
		ClasseTerritorios::ProdOuro = 1;
	}
}

