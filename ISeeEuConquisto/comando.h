#pragma once

#include "includes.h"

using namespace std;

class comando
{
public:
	comando();
	
	void cria(string tipo, int ntipo);

	// FAZER UM FICHEIRO .save DO TIPO TXT OU OUTRO EM QUE VAI ESTAR ENCRIPTADO
	// POR EXEMPLO: mundo1.save, mundo2.save, mundo3.save ETC CONFORME ID (IF mundo1.save EXISTS => mundo2.save ETC.)
	// "ENRIPTAR" DADOS DO SAVE

	// EXEMPLO DE UM mundo1.save:

	// turno=3, ouro=23, pontos=114, cprod=17

	// AQUI VAMOS "ENCRIPTAR" PARA DISTORCER TRAPAÇAS, POR EXEMPLO
	// turno = awkrtefx
	// 3 = 3*28.3

	// ASSIM FICARIA awkretefx=84.9, por exemplo

	void carrega(string nomeFixe);

	// CARREGAR O FICHEIRO .save

	// DESENCRIPTAR O awkretefx=84.9 PARA turno=3 OUTRA VEZ

	void lista(string nomeJogo);

	void consquista(string nometerr);




};
