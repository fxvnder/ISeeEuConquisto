#pragma region Includes e NS

#include "comando.h"
#include "includes.h"
#include "territorios.h"

using namespace std;
using namespace TerritoriosNS;

namespace vetores {
	vector<ClasseTerritorios> Mundo;
	vector<ClasseTerritorios> Imperio;
}

#pragma endregion

#pragma region CRIA

void ComandoCria(string tipo, int ntipo, int HistCriacoes) {
	ClasseTerritorios Territorio;
	vetores::Mundo;
	int novoi = HistCriacoes - ntipo;

	for (int i = novoi; i < HistCriacoes; i++)
	{
		vetores::Mundo.push_back(ClasseTerritorios());
		vetores::Mundo[i].Tipo = tipo;
		vetores::Mundo[i].IDTerr = HistCriacoes;
		vetores::Mundo[i].NomeTerritorio = tipo + to_string(i + 1);
		vetores::Mundo[i].Resistencia = rand() % 10;
		vetores::Mundo[i].ProdOuro = rand() % 10;
		vetores::Mundo[i].ProdProdutos = rand() % 10;
		vetores::Mundo[i].Pontos = rand() % 10;
		cout << "Foi criado " << vetores::Mundo[i].NomeTerritorio << endl;
	}

	//{
	//	if (tipo == vetores::Mundo[x].NomeTerritorio)
	//	{
	//		i++;
	//		ntipoNovo++;
	//	}
	//}

	// if ntipo > 1, tipo = +s
	
}

void ComandosNS::ClasseComandos::CriaTerreno(string tipo, int ntipo, int HistCriacoes) {
	this->tipo = tipo;
	this->ntipo = ntipo;
	this->HistCriacoes = HistCriacoes;

	ComandoCria(tipo, ntipo, HistCriacoes);
}

string ComandosNS::ClasseComandos::getTipo()
{
	return tipo;
}

int ComandosNS::ClasseComandos::getNtipo()
{
	return ntipo;
}

int ComandosNS::ClasseComandos::getHistCriacoes()
{
	return HistCriacoes;
}

#pragma endregion

#pragma region CONQUISTA

void ComandoConquista(string nome) {
	ClasseTerritorios Territorio;
	int FatorSorte = rand() % 100;
	cout << endl;
	for (int i = 0; i < vetores::Mundo.size(); i++)
	{
		//  cout << "A sua seed FatorSorte para esta ronda: " << FatorSorte;
			if (nome == vetores::Mundo[i].NomeTerritorio)
			{ 
				if (FatorSorte <= 70)
				{
					vetores::Imperio.push_back(vetores::Mundo[i]);
					cout << "\nParabens! Conquistou o " << vetores::Imperio[0].NomeTerritorio << "! O seu fator sorte vitorioso foi de " << FatorSorte << "%" << endl;
				}
				else cout << "\nQue azar! O territorio " << vetores::Imperio[0].NomeTerritorio << " nao foi conquistado, pois o seu fator sorte foi de " << FatorSorte << "%" << endl;
			}
			//else
			//{
			//	cout << "\nTerritorio " << vetores::Mundo[i].NomeTerritorio << " dormiu, pois nao foi atacado." << endl;
			//}
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
	
	cout << "Os elementos do vetor imperio sao: \n";
	for (int i = 0; i < Imperio.size(); i++) {
		cout << "\n>>>>> TERRITORIO " << i + 1 << " <<<<<" << endl;
		cout << "\nNome do territorio: " << Imperio.at(i).NomeTerritorio << endl;
		cout << "Resistencia do territorio: " << Imperio.at(i).Resistencia << endl;
		cout << "Producao de ouro do territorio: " << Imperio.at(i).ProdOuro << endl;
		cout << "Producao de produtos do territorio: " << Imperio.at(i).ProdProdutos << endl;
		cout << "Pontos dados pela conquista do territorio: " << Imperio.at(i).Pontos << endl;
		cout << endl;
	}
}

void ComandoListaMundo(vector<ClasseTerritorios> const &Mundo) {
	
	cout << "Os elementos do vetor mundo sao: \n";
	for (int i = 0; i < Mundo.size(); i++) {
		cout << "\n>>>>> TERRITORIO " << i + 1 << " <<<<<" << endl;
		cout << "\nNome do territorio: " << Mundo.at(i).NomeTerritorio << endl;
		cout << "Resistencia do territorio: " << Mundo.at(i).Resistencia << endl;
		cout << endl;
	}
}

void ComandosNS::ClasseComandos::ListaComandos()
{
	ComandoListaMundo(vetores::Mundo);
	ComandoListaImperio(vetores::Imperio);
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


//#pragma region Vetores (DEPOIS MOVER)
//
//vector<ClasseTerritorios> vetorMundo(vector <ClasseTerritorios> Mundo) {
//	
//	return Mundo;
//}
//
//vector<ClasseTerritorios> vetorImperio(vector <ClasseTerritorios> Imperio) {
//	
//	return Imperio;
//}
//
//#pragma endregion
#pragma endregion
