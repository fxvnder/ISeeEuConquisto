#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;

void ComandoCria(string tipo, int ntipo) {
	cout << "ola";
	ClasseTerritorios Territorio;
	vector<ClasseTerritorios> Mundo;
	Mundo.push_back(ClasseTerritorios());

	cout << "Foi/Foram criado(s) ", ntipo, " ", tipo;
}

ComandosNS::ClasseComandos::ClasseComandos()
{
}
