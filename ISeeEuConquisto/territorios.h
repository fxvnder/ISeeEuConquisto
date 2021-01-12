#pragma once

#include "includes.h"
#include "planicie.h"
#include "mundo.h"
#include "comando.h"

using namespace std;


	class ClasseTerritorios {

		string NomeTerritorio, Tipo;
		int IDTerr, Resistencia, ProdProdutos, ProdOuro, Pontos;
		

	public:
		string GetNomeTerr();
		string GetTipoTerr();
		int GetIDTerr();
		int GetResistencia();
		int GetProdProdutos();
		int GetProdOuro();
		int GetPontos();

		
		void SetNomeTerr(string NomeTerr);
		void SetTipoTerr(string TipoTerr);
		void SetIDTerr(int NovoID);
		void SetResistencia(int NovaRes);
		void SetProdP(int NovaPP);
		void SetProdO(int NovaPO);
		void SetPontos(int NovaPontos);

	};

	class ClasseVetores
	{
	public:
		ClasseTerritorios& GetClasseTerritorios(vector<ClasseTerritorios>::size_type NMundo);
		void AddClasseTerritorios(const ClasseTerritorios& NovaClasseTerritorios);
		int GetTamanhoVetor();
		void SetTamanhoVetor(int NovoTamanho);
		vector<ClasseTerritorios> Mundo;
		int vetorsize = 0;	
		
	};

	