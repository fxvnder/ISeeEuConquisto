#pragma once

#include "mundo.h"
#include "territorios.h"

using namespace std;

namespace ComandosNS {

	class ClasseComandos
	{
		int ntipo, HistCriacoes;
		string tipo, nome, filename, filenameC, username;

	public:

		int getNtipo(), getHistCriacoes();
		string getTipo(), getNome(), getNomeFicheiro(), getFilenameC();
		void CriaTerreno(string tipo, int ntipo, int HistCriacoes);
		void GravaFicheiro(string filename);
		void CarregaFicheiro(string filenameC);
		void ListaComandos();
		void ListaComando(int TerritorioListado);
		void ConquistaTerritorios(string nome);
	};
}

void mainmenu();

void programa();

void pause();

void SeparaPalavras(string operacoes, bool ler);

void jogo(bool PrimeiraVez);

void inicio();

void carrega();

void mainmenu();

void programa();

#pragma region Anotacoes

/*
	>>>>>>>> ANOTACOES <<<<<<<<<

			Cria

		// VAI CRIAR O TERRENO, DECIDIR SE � DO TIPO 1, 2 ou 3 COM UM >>> IF/CASE <<< (terr. inicial, continente ou ilha) COM RANDOM NUMS
		// DEPOIS FAZER UM >>> CASE <<< COM RANDOM NUMS PARA DECIDIR SE � UMA PLANICIE, CASTELO, MINA, FORTALEZA, MONTANHA, DUNA
		// EX: CASE DUNA res=4, prod=1

			Carrega

		// CARREGAR UMA LISTA DE TODOS OS FICHEIROS ".save"
		// DESENCRIPTAR O awkretefx=84.9 PARA turno=3 OUTRA VEZ


			Guarda

		// FAZER UM FICHEIRO .save DO TIPO TXT OU OUTRO EM QUE VAI ESTAR ENCRIPTADO
		// POR EXEMPLO: mundo1.save, mundo2.save, mundo3.save ETC CONFORME ID (IF mundo1.save EXISTS => mundo2.save ETC.)
		// "ENRIPTAR" DADOS DO SAVE

		// EXEMPLO DE UM mundo1.save:

		// turno=3, ouro=23, pontos=114, cprod=17

		// AQUI VAMOS "ENCRIPTAR" PARA DISTORCER TRAPA�AS, POR EXEMPLO
		// turno = awkrtefx
		// 3 = 3*28.3

		// ASSIM FICARIA awkretefx=84.9, por exemplo

			Lista

		// VER OS DADOS DO JOGO, EU FA�O O OUTPUT
		// E LITERALMENTE SO MOSTRAR EXEMPLO:

		// EM 8 TURNOS JA FIZESTE 255 OURO, 122 PRODUTOS, JA CONQUISTASTE 3 DUNAS E 2 FORTALEZAS
*/
#pragma endregion
