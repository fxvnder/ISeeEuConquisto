#pragma once

#include "includes.h"
#include "planicie.h"
#include "mundo.h"
#include "comando.h"

using namespace std;

namespace TerritoriosNS {
	class ClasseTerritorios {
		
	public:
		ClasseTerritorios();
		string NomeTerritorio = "";
		string Tipo = "";
		int IDTerr = 0;
		int Resistencia = 0;
		int ProdProdutos = 0;
		int ProdOuro = 0;
		int Pontos = 0;
		int setID(int id);
		int getID();
		int idvar;
	};
	

}

