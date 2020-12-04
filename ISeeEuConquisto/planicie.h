#pragma once

#include "includes.h"

using namespace std;

class planicie :public territorios{

public:
	planicie();
	~planicie();

private:
	string nometerr;
	int res;
	int cprod;
	int couro;
	int pontos;
};

planicie::planicie()
{
}

planicie::~planicie()
{
}