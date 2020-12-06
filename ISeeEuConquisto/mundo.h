#pragma once

#include "includes.h"
#include "territorios.h"
#include "comando.h"

using namespace std;
using namespace TerritoriosNS;

class mundo
{
public:
	vector<unique_ptr<ClasseTerritorios>> VectorMundo;

};
