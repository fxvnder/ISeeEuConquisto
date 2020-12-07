#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace TerritoriosNS;
using namespace std;

void ComandoCria(string tipo, int ntipo) {
	ClasseTerritorios Territorio;
	vector<ClasseTerritorios> Mundo;
	Mundo.push_back(ClasseTerritorios());

	cout << "Foi/Foram criado(s) ", ntipo, " ", tipo;
}

