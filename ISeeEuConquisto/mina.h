#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;

namespace ImperioNS {
	class ClasseMina : public ClasseTerritorios
	{
	public:
		// p/ user criar minas
	private:

	};

	void ClasseMina3TurnosAno()
	{
		ClasseTerritorios Territorios;
		Territorios.NomeTerritorio = "Mina";
		Territorios.Resistencia = 5;
		Territorios.ProdOuro = 1;
		Territorios.Pontos = 1;
	}

	void ClasseMina3OutrosTurnosAno()
	{
		ClasseTerritorios Territorios;
		Territorios.NomeTerritorio = "Mina";
		Territorios.Resistencia = 5;
		Territorios.ProdOuro = 2;
		Territorios.Pontos = 1;
	}
}