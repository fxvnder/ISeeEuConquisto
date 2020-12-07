#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;

#pragma region Vetores (DEPOIS MOVER)

vector<ClasseTerritorios> vetorMundo() {
	vector<ClasseTerritorios> Mundo;
	return Mundo;
}

vector<ClasseTerritorios> vetorImperio() {
	vector<ClasseTerritorios> Imperio;
	return Imperio;
}

#pragma endregion

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
	vector<ClasseTerritorios> Imperio = vetorImperio();
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

void ComandoGrava(string nomeficheiro) {

	ofstream SaveFile;
	SaveFile.open(nomeficheiro + ".save", ios::out | ios_base::app);
}


void ComandosNS::ClasseComandos::GravaFicheiro(string filename)
{
	this->filename = filename; 

	ComandoGrava(filename);
}

string ComandosNS::ClasseComandos::getNomeFicheiro()
{
	return filename;
}

#pragma endregion

#pragma region LISTA

void ComandosNS::ClasseComandos::ListaComandos(string nomeJogo)
{
}
#pragma endregion

#pragma region CARREGA


void CarregaFicheiro(string filenameC) {
	string nLinhas;
	ifstream OpenFile(filenameC + ".save");

	if (OpenFile.is_open())
	{
		while (!OpenFile.eof()) {
			getline(OpenFile, nLinhas);
		}
		OpenFile.close();
	}
	else {
		cout << "\n\n\n>>> ERRO A CARREGAR O FICHEIRO!!! <<<";
	}
}

void ComandosNS::ClasseComandos::CarregaFicheiro(string filenameC)
{
	this->filenameC = filenameC;

	CarregaFicheiro(filenameC);
}

string ComandosNS::ClasseComandos::getFilenameC()
{
	return filenameC;
}

#pragma endregion
