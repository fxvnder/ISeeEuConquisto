#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class TerritorioInicial : public ClasseTerritorios
{
	public:
		//

	private:
};

void TerritorioInicial()
{
	ClasseTerritorios TerrInicial;
	TerrInicial.Resistencia = 9;
	TerrInicial.ProdOuro = 1;
	TerrInicial.ProdProdutos = 1;
}