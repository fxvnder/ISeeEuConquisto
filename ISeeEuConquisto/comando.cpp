#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;

vector<ClasseTerritorios> vetorMundo() {
	vector<ClasseTerritorios> Mundo;
	return Mundo;
}

#pragma region CRIA

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

#pragma endregion

#pragma region CONQUISTA

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

void ComandosNS::ClasseComandos::ConquistaTerritorios(string nome) {
	this->nome = nome;

	ComandoConquista(nome);
}


string ComandosNS::ClasseComandos::getNome()
{
	return nome;
}

#pragma endregion

#pragma region GRAVA

void ComandoGrava(string nomeficheiro, string username) {

	ofstream SaveFile;
	SaveFile.open(nomeficheiro + ".save");
	SaveFile << "username = " << username << endl;
	SaveFile.close();

}


void ComandosNS::ClasseComandos::GravaFicheiro(string filename, string username)
{
}

string ComandosNS::ClasseComandos::getNomeFicheiro()
{
	return filename;
}

string ComandosNS::ClasseComandos::getUsername()
{
	return username;
}

#pragma endregion

#pragma region LISTA

void ComandosNS::ClasseComandos::ListaComandos(string nomeJogo)
{
}
#pragma endregion

#pragma region CARREGA


int CarregaFicheiro(string filename, string username) {
 string nLinhas;
 ifstream OpenFile(filename + ".save");


	if (OpenFile.is_open())
	{
	while (getline(OpenFile, nLinhas))
	{
		cout << nLinhas << endl;
		nLinhas;
	}
		OpenFile.close();
		return 1;
	}
	else {
		cout << "\n\n\n>>> ERRO A CARREGAR O FICHEIRO!!! <<<";
		return 0;
	}
}

#pragma endregion