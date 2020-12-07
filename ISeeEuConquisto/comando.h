#pragma once

#include "mundo.h"
#include "territorios.h"

using namespace std;

namespace ComandosNS {

	class ClasseComandos
	{
	protected:
		string tipo;
		int ntipo;
	public:
		ClasseComandos();
		// comando();
	
		void cria(string tipo, int ntipo);
		string getTipo();
		int getNtipo();
		

		// VAI CRIAR O TERRENO, DECIDIR SE É DO TIPO 1, 2 ou 3 COM UM >>> IF/CASE <<< (terr. inicial, continente ou ilha) COM RANDOM NUMS
		// DEPOIS FAZER UM >>> CASE <<< COM RANDOM NUMS PARA DECIDIR SE É UMA PLANICIE, CASTELO, MINA, FORTALEZA, MONTANHA, DUNA
		// EX: CASE DUNA res=4, prod=1



		void grava(string filename, string username) {
			// FAZER UM FICHEIRO .save DO TIPO TXT OU OUTRO EM QUE VAI ESTAR ENCRIPTADO
			// POR EXEMPLO: mundo1.save, mundo2.save, mundo3.save ETC CONFORME ID (IF mundo1.save EXISTS => mundo2.save ETC.)
			// "ENRIPTAR" DADOS DO SAVE

			// EXEMPLO DE UM mundo1.save:

			// turno=3, ouro=23, pontos=114, cprod=17

			// AQUI VAMOS "ENCRIPTAR" PARA DISTORCER TRAPAÇAS, POR EXEMPLO
			// turno = awkrtefx
			// 3 = 3*28.3

			// ASSIM FICARIA awkretefx=84.9, por exemplo

			ofstream SaveFile;
			SaveFile << "username = " << username << endl;
			SaveFile.open(filename + ".save");
			SaveFile << "isto e um teste lol.\n";
			SaveFile.close();

		}
	


		int carrega(string filename) {

			// CARREGAR UMA LISTA DE TODOS OS FICHEIROS ".save"
			// DESENCRIPTAR O awkretefx=84.9 PARA turno=3 OUTRA VEZ
			
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



		void lista(string nomeJogo) {
			// VER OS DADOS DO JOGO, EU FAÇO O OUTPUT
			// E LITERALMENTE SO MOSTRAR EXEMPLO:

			// EM 8 TURNOS JA FIZESTE 255 OURO, 122 PRODUTOS, JA CONQUISTASTE 3 DUNAS E 2 FORTALEZAS


		}

		void consquista(string nometerr) {


		}




	};

}
