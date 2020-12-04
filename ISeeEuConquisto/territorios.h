#pragma once

#include "includes.h"
#include "planicie.h"

using namespace std;

class territorios{
protected:
	string nometerr;
	int res;
	int cprod;
	int couro;
	int pontos;
public:
	territorios(string nometerr);
	void gettipo(string nometerr);
	territorios();

};
