#pragma once


#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class ClasseFortaleza{
		
	public:
		string NomeFortaleza, TipoFortaleza;
		int IDTerrFortaleza, ResistenciaFortaleza, ProdProdutosFortaleza, ProdOuroFortaleza, PontosFortaleza;
		int idvar = 0;
		int setID(int id);
		int getID();
	};
	
void CriaFortaleza(int id, int ntipo);