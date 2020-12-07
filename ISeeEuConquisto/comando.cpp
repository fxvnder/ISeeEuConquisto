#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;



	// COMANDO CRIA



	void ComandoCria(string tipo, int ntipo) {
		ClasseTerritorios Territorio;
		vector<ClasseTerritorios> Mundo;
		for (int i = 0; i < ntipo; i++)
		{
			Mundo.push_back(ClasseTerritorios());
			Mundo[i].NomeTerritorio = tipo + to_string(i + 1);
			cout << "Foi criado " << Mundo[i].NomeTerritorio << endl;
		}
		// if ntipo > 1, tipo = +s
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
		Imperio.push_back(ClasseTerritorios());
		cout << "\nFoi conquistado ", Imperio[0].NomeTerritorio;
		cout << endl;
		/*
		vector<int> dataVec;

		int dataArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		unsigned dataArraySize = sizeof(dataArray) / sizeof(int);

		// Method 1: Copy the array to the vector using back_inserter.
		{
			copy(&dataArray[0], &dataArray[dataArraySize], back_inserter(dataVec));
		}
		*/
	}

	void ComandosNS::ClasseComandos::conquista(string nome) {
		this->nome = nome;

		ComandoConquista(nome);
	}


	string ComandosNS::ClasseComandos::getNome()
	{
		return nome;
	}