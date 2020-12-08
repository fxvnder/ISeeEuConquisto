#pragma once

#include "mundo.h"
#include "territorios.h"

using namespace std;

namespace ComandosNS {

	class ClasseComandos
	{
	protected:

	public:
		//vars
		//static int idntipo;
		int ntipo;
		int getNtipo();
		string tipo, nome, filename, filenameC, username;
		string getTipo(), getNome(), getNomeFicheiro(), getFilenameC();

		//funcoes
		void CriaTerreno(string tipo, int ntipo);
		void GravaFicheiro(string filename);
		void CarregaFicheiro(string filenameC);
		void ListaComandos();
		void ConquistaTerritorios(string nome);
	};

}

#pragma region Anotacoes

/*
	>>>>>>>> ANOTACOES <<<<<<<<<

			Cria

		// VAI CRIAR O TERRENO, DECIDIR SE É DO TIPO 1, 2 ou 3 COM UM >>> IF/CASE <<< (terr. inicial, continente ou ilha) COM RANDOM NUMS
		// DEPOIS FAZER UM >>> CASE <<< COM RANDOM NUMS PARA DECIDIR SE É UMA PLANICIE, CASTELO, MINA, FORTALEZA, MONTANHA, DUNA
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

		// AQUI VAMOS "ENCRIPTAR" PARA DISTORCER TRAPAÇAS, POR EXEMPLO
		// turno = awkrtefx
		// 3 = 3*28.3

		// ASSIM FICARIA awkretefx=84.9, por exemplo

			Lista

		// VER OS DADOS DO JOGO, EU FAÇO O OUTPUT
		// E LITERALMENTE SO MOSTRAR EXEMPLO:

		// EM 8 TURNOS JA FIZESTE 255 OURO, 122 PRODUTOS, JA CONQUISTASTE 3 DUNAS E 2 FORTALEZAS
*/
#pragma endregion
