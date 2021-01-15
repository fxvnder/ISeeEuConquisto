#include "fortaleza.h"
#include "territorios.h"
#include "includes.h"


using namespace std;
using namespace TerritoriosNS;

 int ClasseFortaleza::setID(int id){
     return id;
 }

 int ClasseFortaleza::getID(){
      return idvar;
 }

void CriaFortaleza(ClasseFortaleza Fortaleza) {
   
    {   
        
        int idcoiso = Fortaleza.getID();
        Fortaleza.TipoFortaleza= "Fortaleza";
        Fortaleza.IDTerrFortaleza = Fortaleza.setID(idcoiso++);
        Fortaleza.NomeFortaleza = "Fortaleza" + idcoiso;
        Fortaleza.ResistenciaFortaleza = 8;
        Fortaleza.ProdOuroFortaleza = 0;
        Fortaleza.ProdProdutosFortaleza = 0;
        Fortaleza.PontosFortaleza = 1;
        cout << "Foi criado " << Fortaleza.NomeFortaleza << endl;
    }
};



