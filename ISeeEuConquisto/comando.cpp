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
	for (int i = 0; i < Mundo.size(); i++)
	{
		if (nome == Mundo[i].NomeTerritorio)
		{ 
			Imperio.push_back(Mundo[i]);
			cout << "\nFoi conquistado ", Imperio[0].NomeTerritorio;
		}
		else
		{
			cout << "Território não encontrado" << endl;
		}
	}
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

void ComandoListaImperio(vector<ClasseTerritorios> const &Imperio) {
	
	cout << "Os elementos do vetor imperio sao: ";
	for (int i = 0; i < Imperio.size(); i++)
		cout << Imperio.at(i).Resistencia << endl;

}

void ComandoListaMundo(vector<ClasseTerritorios> const &Mundo) {
	
	cout << "Os elementos do vetor mundo sao: ";
	for (int i = 0; i < Mundo.size(); i++)
		cout << Mundo.at(i).Resistencia << endl;

}

void ComandosNS::ClasseComandos::ListaComandos()
{
	vector<ClasseTerritorios> Imperio = vetorImperio();
	vector<ClasseTerritorios> Mundo = vetorMundo();
	ComandoListaImperio(Imperio);
	ComandoListaMundo(Mundo);
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

#pragma region codigo testes

//#include <list>
//list<int> dest(Imperio.begin(), Imperio.end());
//cout << "Conteudo do vetor Imperio:\n";
//for (const int& i : dest) {
//	cout << i << " " << endl;
//}
//
//list<int> dest(Mundo.begin(), Mundo.end());
//cout << "Conteudo do vetor Mundo:\n";
//for (const int& i : dest) {
//	cout << i << " " << endl;
//}

#pragma endregion
