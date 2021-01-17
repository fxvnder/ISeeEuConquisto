#include "tecnologias.h"
#include "includes.h"
#include "comando.h"

using namespace std;

void CriaDrones() {
	cout << R"(
     __      ()      __
    |::\     ||     /::\
    \:::\.-~~~~~~-./:::/ 
     \::/   XXXX   \::/
  ()===|    XEYX    |===()
      _`+--Go.Pro--+'_
     /::<\.__..__./>::\
    /:::::>  ||  <:::::\
   /--.::/   ||   \::.--\  
   |:::\/    ()    \/:::|      
   `---'            `---'
)";
	cout << "\nEsta tecnologia vai fazer com que o limite maximo da forca militar passe para 5. Custa 3 unidades de ouro." << endl;
}

void CriaMisseis() {
    cout << R"(
     _.-^^---....,,--       
 _--                  --_  
<                        >)
|                         | 
 \._                   _./  
    ```--. . , ; .--'''       
          | |   |             
       .-=||  | |=-.   
       `-=#$%&%$#=-'   
          | ;  :|     
 _____.,-#%&$@%#&#~,._____
)";
	cout << "\nEsta tecnologia e necessaria para conquistar ilhas. Custa 4 unidades de ouro." << endl;
}

void CriaDefesas() {
    cout << R"(
   |\                     /)
 /\_\\__               (_//
|   `>\-`     _._       //`)
 \ /` \\  _.-`:::`-._  //
  `    \|`    :::    `|/
        |     :::     |
        |.....:::.....|
        |:::::::::::::|
        |     :::     |
        \     :::     /
         \    :::    /
          `-. ::: .-'
           //`:::`\\
          //   '   \\
         |/         \\
)";
	cout << "\nAcrescenta 1 unidade de resistencia do territorio invadido durante um evento. Custa 4 unidades de ouro." << endl;
}

int CriaBolsa(int bolsa) {
	bolsa = 1;
    cout << R"(
    __..,,... .,,,,,.
''''        ,'        ` .
          ,'  ,.  ..      `  .
           `.,'      ..           `
__..,.             .  ..     .
        ` .       .  `.  .` `
            ,  `.  `.  `._|,..
             .  `.  `..'
                ` -'`''
)";
	 cout << "\nTorna possivel as trocas entre produtos e ouro. Custa 2 unidades de ouro." << endl;
	return bolsa;
}

void CriaBanco() {
    cout << R"(
                ______________
    __,.,---'''''              '''''---..._
 ,-'             .....:::''::.:            '`-.
'           ...:::.....       '                `
            ''':::'''''       .               ,
|'-.._           ''''':::..::':          __,,-
 '-.._''`---.....______________.....---''__,,-
      ''`---.....______________.....---''
)";
	cout << "\nAumenta em 2 unidades a capacidade de armazenamento do armazem e do cofre. Custa 3 unidades de ouro." << endl;
}