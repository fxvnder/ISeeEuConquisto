#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;



	// COMANDO CRIA

vector<ClasseTerritorios> vetorMundo() {
	vector<ClasseTerritorios> Mundo;
	return Mundo;
}

	void ComandoCria(string tipo, int ntipo) {
		ClasseTerritorios Territorio;
		vector<ClasseTerritorios> Mundo = vetorMundo();
		for (int i = 0; i < ntipo; i++)
		{
			Mundo.push_back(ClasseTerritorios());
			Mundo[i].NomeTerritorio = tipo + to_string(i + 1);
			cout << "Foi criado " << Mundo[i].NomeTerritorio << endl;
		}
		// if ntipo > 1, tipo = +s
		Mundo = vetorMundo();
	}

	void ComandosNS::ClasseComandos::CriaTerreno(string tipo, int ntipo) {
		this->tipo = tipo;
		this->ntipo = ntipo;

		ComandoCria(tipo, ntipo);
	}

	string ComandosNS::ClasseComandos::getTipo()
	{
		return tipo;
	}

	int ComandosNS::ClasseComandos::getNtipo()
	{
		return ntipo;
	}



	// COMANDO CONQUISTA



	void ComandoConquista(string nome) {
		ClasseTerritorios Territorio;
		vector<ClasseTerritorios> Imperio;
		vector<ClasseTerritorios> Mundo = vetorMundo();
		cout << Mundo[1].NomeTerritorio;
		cout << Mundo[0].NomeTerritorio;
		for (int i = 0; i < Mundo.size(); i++)
		{
			if (nome == Mundo[i].NomeTerritorio)
				Imperio.push_back(Mundo[i]);
			else
			{
				cout << "Território não encontrado" << endl;
			}
		}
		cout << "\nFoi conquistado ", Imperio[0].NomeTerritorio;
		cout << endl;

	}

	void ComandosNS::ClasseComandos::conquista(string nome) {
		this->nome = nome;

		ComandoConquista(nome);
	}


	string ComandosNS::ClasseComandos::getNome()
	{
		return nome;
	}