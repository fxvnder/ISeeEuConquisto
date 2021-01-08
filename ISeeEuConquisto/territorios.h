#pragma once

#include "includes.h"
#include "planicie.h"
#include "mundo.h"
#include "comando.h"

using namespace std;

namespace TerritoriosNS {
	class ClasseTerritorios {

	public:
		ClasseTerritorios();
		string GetNomeTerr() { return NomeTerritorio; }
		string GetTipoTerr() { return Tipo; }
		int GetIDTerr() { return IDTerr; }
		int GetResistencia() { return Resistencia; }
		int GetProdProdutos() { return ProdProdutos; }
		int GetProdOuro() { return ProdOuro; }
		int GetPontos() { return Pontos; }

		
		void SetNomeTerr(string NomeTerr) { NomeTerritorio = NomeTerr; }
		void SetTipoTerr(string TipoTerr) { Tipo = TipoTerr; }
		void SetIDTerr(int NovoID) { IDTerr = NovoID; }
		void SetResistencia(int NovaRes) { Resistencia = NovaRes; }
		void SetProdP(int NovaPP) {ProdProdutos = NovaPP;}
		void SetProdO(int NovaPO) { ProdOuro = NovaPO; }
		void SetPontos(int NovaPontos) { Pontos = NovaPontos; }

	private:
		
		string NomeTerritorio;
		string Tipo;
		int IDTerr;
		int Resistencia;
		int ProdProdutos;
		int ProdOuro;
		int Pontos;
	};

	class ClasseVetores
	{
	public:
		ClasseTerritorios& GetClasseTerritorios(vector<ClasseTerritorios>::size_type NMundo);
		void AddClasseTerritorios(const ClasseTerritorios& NovaClasseTerritorios);
		int GetTamanhoVetor() { return vetorsize; };
		void SetTamanhoVetor(int NovoTamanho) { vetorsize = NovoTamanho; };
		
		
	private:
		vector<ClasseTerritorios> Mundo;
		int vetorsize = 0;
	};

	void ClasseVetores::AddClasseTerritorios(const ClasseTerritorios& NovaClasseTerritorios) {
		Mundo.push_back(NovaClasseTerritorios);
	}

	ClasseTerritorios& ClasseVetores::GetClasseTerritorios(vector<ClasseTerritorios>::size_type NMundo) {
		return Mundo[NMundo];
	}
}
	