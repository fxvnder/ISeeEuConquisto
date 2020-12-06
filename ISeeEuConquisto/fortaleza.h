#pragma once

#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;


class ClasseFortaleza : public ClasseTerritorios
{
public:
	// p/ user criar fortalezas
private:

};

void ClasseFortaleza()
{
	ClasseTerritorios Territorios;
	Territorios.NomeTerritorio = "Fortaleza";
	Territorios.Resistencia = 8;
	Territorios.Pontos = 1;
}