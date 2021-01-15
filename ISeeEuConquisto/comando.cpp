#pragma region Includes e NS

#include "comando.h"
#include "includes.h"
#include "territorios.h"
#include "fortaleza.h"

using namespace std;
using namespace TerritoriosNS;
using namespace ComandosNS;

namespace vetores {
 // CLASSE PARA INCORPORAR vv
	vector<ClasseTerritorios> Mundo;
	vector<ClasseTerritorios> Imperio;
}

namespace VariaveisImportantes
{
    string username, nomeficheiro;
    int QuantCria = 0;
}

#pragma region UserOS

// vai detetar o OS do utilizador

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
#define WINDOWS 1
#elif defined(__APPLE__) || defined(TARGET_OS_MAC) || defined(__linux__) || defined(__unix__)
#define LINUX 1
#else
#error "PC da NASA?"
#endif

void clear() { // LIMPA O ECRÃ SEM O CONIO.H \\ CLRSCR()
#ifdef WINDOWS
    system("cls");
#endif
#ifdef LINUX
    system("clear");
#endif
}

void syspause() { // SYS.PAUSE = PRESS ANY KEY TO CONTINUE
#ifdef WINDOWS
    system("pause");
#endif
#ifdef LINUX
    system("read");
#endif
}

// COMENTARIOS COM IDEIAS ANTIGAS:

// PERGUNTAR AO UTILIZADOR QUAL O SISTEMA OPERATIVO ESTA A USAR, ASSIM SENDO TIRA-SE O DEFINE E VAI PASSAR A SER AUTOMÁTICO

// ^^ DONE.

//#define WINDOWS 1 // SE O UTILIZADOR ESTIVER A USAR LINUX SUBSTITUIR WINDOWS POR LINUX
//#define LINUX 1 // IDEM

// ^^ JÁ NÃO É NECESSÁRIO.

#pragma endregion

#pragma endregion

#pragma region CRIA

void ComandoCria(string tipo, int ntipo) {
    vetores::Mundo;
    ClasseTerritorios TerritorioF;
    if(tipo == "fortaleza"){
        for (int i = 0; i < ntipo; i++) {
            
            vetores::Mundo.push_back(ClasseTerritorios());
            int idcoiso = TerritorioF.getID();
            vetores::Mundo[i].Tipo = "Fortaleza";
            vetores::Mundo[i].IDTerr = TerritorioF.setID(idcoiso++);
            vetores::Mundo[i].NomeTerritorio = "Fortaleza" + to_string(idcoiso);
            vetores::Mundo[i].Resistencia = 8;
            vetores::Mundo[i].ProdOuro = 0;
            vetores::Mundo[i].ProdProdutos = 0;
            vetores::Mundo[i].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[i].NomeTerritorio << endl;
        }
    }
    else{
        for (int i = 0; i < ntipo; i++)
            {
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[i].Tipo = tipo;
            vetores::Mundo[i].IDTerr = ntipo;
            vetores::Mundo[i].NomeTerritorio = tipo + to_string(i + 1);
            vetores::Mundo[i].Resistencia = rand() % 10;
            vetores::Mundo[i].ProdOuro = rand() % 10;
            vetores::Mundo[i].ProdProdutos = rand() % 10;
            vetores::Mundo[i].Pontos = rand() % 10;
            cout << "Foi criado " << vetores::Mundo[i].NomeTerritorio << endl;
            }
        }

}

void ComandosNS::ClasseComandos::CriaTerreno(string tipo, int ntipo) {
    this->tipo = tipo;
    this->ntipo = ntipo;

    ComandoCria(tipo, ntipo);
}

string ComandosNS::ClasseComandos::getTipo()
{
    return tipo;
}

int ComandosNS::ClasseComandos::getNtipo()
{
    return ntipo;
}

#pragma endregion

#pragma region CONQUISTA

void ComandoConquista(string nome) {
    ClasseTerritorios Territorio;
    int FatorSorte = rand() % 6;
    bool vaiconquistar = true, existe = false;
    cout << endl;

    for (int x = 0; x < vetores::Imperio.size(); x++)
    {
        if (nome == vetores::Imperio[x].NomeTerritorio) {
            vaiconquistar = false;
            cout << "\nEsse territorio ja te pertence, malandro! Nao sejas ganancioso!" << endl;
        }         
    }

    if (vaiconquistar == true)
    {
        for (int i = 0; i < vetores::Mundo.size(); i++)
        {
            //  cout << "A sua seed FatorSorte para esta ronda: " << FatorSorte;
            if (nome == vetores::Mundo[i].NomeTerritorio)
            {
                existe = true;
                if (FatorSorte >= 3)
                {
                    vetores::Imperio.push_back(vetores::Mundo[i]);
                    cout << "\nParabens! Conquistou o " << vetores::Mundo[i].NomeTerritorio << "! O seu fator sorte vitorioso foi de " << FatorSorte << "%" << endl;
                }
                else cout << "\nQue azar! O territorio " << vetores::Mundo[i].NomeTerritorio << " nao foi conquistado, pois o seu fator sorte foi de " << FatorSorte << "%" << endl;
            }
            //else
            //{
            //	cout << "\nTerritorio " << vetores::Mundo[i].NomeTerritorio << " dormiu, pois nao foi atacado." << endl;
            //}
        }

        if (existe == false)
        {
            cout << "\nTerritorio nao encontrado." << endl;
        }
    }

    cout << endl;

}

void ComandosNS::ClasseComandos::ConquistaTerritorios(string nome) {
    this->nome = nome;

    ComandoConquista(nome);
}


string ComandosNS::ClasseComandos::getNome()
{
    return nome;
}

#pragma endregion

#pragma region GRAVA

void ComandoGrava(string nomeficheiro) {

    ofstream SaveFile;
    SaveFile.open(nomeficheiro + ".save", ios::out | ios_base::app);
}


void ComandosNS::ClasseComandos::GravaFicheiro(string filename)
{
    this->filename = filename;

    ComandoGrava(filename);
}

string ComandosNS::ClasseComandos::getNomeFicheiro()
{
    return filename;
}

#pragma endregion

#pragma region LISTA

void ComandoListaImperio(vector<ClasseTerritorios> const& Imperio) {
    for (int i = 0; i < Imperio.size(); i++) {
        cout << "\n>>>>> TERRITORIO " << i + 1 << " <<<<<" << endl;
        cout << "\nNome do territorio: " << Imperio.at(i).NomeTerritorio << endl;
        cout << "Resistencia do territorio: " << Imperio.at(i).Resistencia << endl;
        cout << "Producao de ouro do territorio: " << Imperio.at(i).ProdOuro << endl;
        cout << "Producao de produtos do territorio: " << Imperio.at(i).ProdProdutos << endl;
        cout << "Pontos dados pela conquista do territorio: " << Imperio.at(i).Pontos << endl;
        cout << endl;
    }
}

void ComandoListaMundo(vector<ClasseTerritorios> const& Mundo) {
    for (int i = 0; i < Mundo.size(); i++) {
        cout << "\n>>>>> TERRITORIO " << i + 1 << " <<<<<" << endl;
        cout << "\nNome do territorio: " << Mundo.at(i).NomeTerritorio << endl;
        cout << "Resistencia do territorio: " << Mundo.at(i).Resistencia << endl;
        cout << endl;
    }
}

void ComandosNS::ClasseComandos::ListaComandos()
{
    cout << "\n\n>>> TERRITORIOS CRIADOS <<<\n" << endl;
    ComandoListaMundo(vetores::Mundo);
    cout << "\n\n>>> TERRITORIOS CONQUISTADOS <<<\n" << endl;
    ComandoListaImperio(vetores::Imperio);
    cout << endl;
}
#pragma endregion

#pragma region CARREGA


void CarregaFicheiro(string filenameC) {
    string nLinhas;
    ifstream OpenFile(filenameC + ".save");

    if (OpenFile.is_open())
    {
        while (!OpenFile.eof()) {
            getline(OpenFile, nLinhas);
        }
        OpenFile.close();
    }
    else {
        cout << "\n\n\n>>> ERRO A CARREGAR O FICHEIRO!!! <<<";
    }
}

void ComandosNS::ClasseComandos::CarregaFicheiro(string filenameC)
{
    this->filenameC = filenameC;

    CarregaFicheiro(filenameC);
}

string ComandosNS::ClasseComandos::getFilenameC()
{
    return filenameC;
}

#pragma endregion

#pragma region PASSA

void ComandoPassaMain(){

	&ClasseComandos::nextTurno;

}

void ComandosNS::ClasseComandos::nextTurno()
{
	&ClasseComandos::getTurno;
	ClasseComandos::setTurno(turno++);

}
int ClasseComandos::setTurno(int turno)
{
	return turno;
}
int ClasseComandos::getTurno() {
	return turno;
}
#pragma endregion

void pause() { // PAUSA EM PRINTS
    cin.ignore();
    cin.get();
}

void SeparaPalavras(string operacoes, bool ler)
{
    vector<string> VectorComandos;
    ClasseComandos ClasseComandosMain;
    string PalavraSeparada;
    stringstream StrStream(operacoes);

    while (StrStream >> PalavraSeparada) {
        VectorComandos.push_back(PalavraSeparada);
    }

    if (VectorComandos[0] == "cria")
    {
        stringstream Tamanho(VectorComandos[2]);
        int SeguraInt = 0;
        Tamanho >> SeguraInt;
        ClasseComandosMain.CriaTerreno(VectorComandos[1], SeguraInt);
        if (ler == false) {
            ofstream SaveFile;
            SaveFile.open(VariaveisImportantes::nomeficheiro + ".save", ios::out | ios_base::app);
            SaveFile << VectorComandos[0] << " " << VectorComandos[1] << " " << VectorComandos[2] << endl;
        }
    }
    else if (VectorComandos[0] == "conquista")
    {
        stringstream Tamanho(VectorComandos[1]);
        ClasseComandosMain.ConquistaTerritorios(VectorComandos[1]);
    }
    else if (VectorComandos[0] == "lista")
    {
        if (VectorComandos.size() > 1) {
            //ClasseComandosMain.ListaComando(VectorComandos[1]);
        }
        else
        {
            ClasseComandosMain.ListaComandos();
        }
    }
    else if (VectorComandos[0] == "passa"){   
        ComandoPassaMain();
    }
    else if (VectorComandos[0] == "nickname")
    {
        VariaveisImportantes::username = VectorComandos[1];
        if (ler == true) cout << "\nO teu nickname: " << VectorComandos[1] << endl;
        if (ler == false) {
            ofstream SaveFile;
            SaveFile.open(VariaveisImportantes::nomeficheiro + ".save", ios::out | ios_base::app);
            SaveFile << VectorComandos[0] << " " << VectorComandos[1] << endl;
        }
    }
    else if (VectorComandos[0] == "ajuda")
    {
        clear();

        cout << R"(
        
        >>> AJUDA <<<

        Bem-vindo ao ISEC. Estes são os comandos que deves saber para aprender a jogar!

        > COMANDOS PRE-JOGO

        >> CRIA x y = VAI CRIAR UM TERRITORIO DO TIPO x E DA QUANTIDADE y.

        >> LISTA (x) = VAI LISTAR TODOS OS TERRITORIOS DO MUNDO OU UM INDIVIDUAL (x)

        >> NICKNAME x = VAI MUDAR O TEU NICKNAME IN-GAME. SÓ O PODES FAZER ENQUANTO O JOGO NÃO COMEÇAR!

        >> SAIR = ...pois

        > COMANDOS POS-JOGO

        >> CONQUISTA x = VAIS TENTAR CONQUISTAR O TERRITORIO x! BOA SORTE!

        >> LISTA (x) = VAI LISTAR TODOS OS TERRITORIOS DO MUNDO E DO TEU IMPERIO, OU UM INDIVIDUAL (x)
        
        )";
    }
    else if (VectorComandos[0] == "sair") cout << "\n\n\nBye bye!" << endl;
    else cout << "\nComando " << VectorComandos[0] << " nao reconhecido." << endl;
}

void jogo(bool PrimeiraVez) {
    ClasseComandos ClasseComandosMain;
    string operacao;
    string StringIndividual;
    vector<ClasseTerritorios> Mundo;
    ofstream SaveFile;

    if (PrimeiraVez == true) {
        clear();
        cout << R"(
        
        BEM-VINDO AO ISEC.

        Bem, vejo que e a primeira vez que estas a jogar isto, entao vamos aprender a jogar!

        Tu vais comecar no DEIS, esse e o teu territorio inicial, que a cada jogada que fazes te vai dar:
          >>>  DEIS (Resistencia: 9) => 1 unidade de produtos e 1 de ouro
        Como e obvio, o teu terreno inicial nao te vai dar pontos de vitoria, mas a partir daqui, tu tratas disso!

        A cada jogada que fazes o teu progresso vai ser gravado e podes retomar quando quiseres, se quiseres.

        Como vais querer guardar o nome deste imperio? )";

        getline(cin, VariaveisImportantes::nomeficheiro);

        cout << VariaveisImportantes::nomeficheiro;
        ClasseComandosMain.GravaFicheiro(VariaveisImportantes::nomeficheiro);
        SeparaPalavras("nickname " + VariaveisImportantes::username, false);
        cout << "\nParabens, " << VariaveisImportantes::username << "! Vamos agora comecar a jogar! Para sair escreve sair" << endl;
        cout << ">>> comandos disponiveis: cria / lista / nickname / ajuda / sair\n>>>>>Se te sentires preparado para comecar o jogo escreve comecar" << endl;
        do
        {
            cout << "Insira um comando aqui: ";

            getline(cin, operacao);

            if (operacao.empty()) {
                cout << "\nTens de dizer um comando, amigo" << endl;
            }
            else SeparaPalavras(operacao, false);

        } while (operacao != "sair");

        SaveFile.close();

    }
    else
    {
        cout << "Bem vindo de volta, " << VariaveisImportantes::username;
        do
        {
            cout << "\nInsira um comando aqui: ";

            getline(cin, operacao);

            if (operacao.empty()) {
                cout << "\nPor favor escreva alguma coisa";
            }
            else
            {
                SeparaPalavras(operacao, false);
            }

        } while (operacao != "sair");

        SaveFile.close();
    }

}

void inicio() {
    string operacao;
    clear();
    cout << "Bem vindo a aventura, amigo, bem-haja! Vamos comecar?...\n";
    cout << "\n...espera la... ainda nem sei o teu nome!...";
    cout << "\n\nEntao? Como te chamas?";
    cout << "\n\nInserir Nickname: ";
    cin.ignore(1000, '\n');
    getline(cin, VariaveisImportantes::username);
    cout << "\n" << VariaveisImportantes::username << "... e isso? Prazer em conhecer-te!";
    cout << "\nBem, vieste em boa altura, estamos mesmo a precisar de uma maozinha aqui... Junta-te a nos!";
    pause();
    clear();
    cout << R"(
   /\                                                        /\
  |  |                                                      |  |
 /----\                                                    /----\
[______]                                                  [______]
 |    |         _____                        _____         |    |
 |[]  |        [     ]                      [     ]        |  []|
 |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |
 |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |
 |             |     |/'    DEIS--ISEC    '\|     |             |
  \  []        |     |    /'    ||    '\    |     |        []  /
   |      []   |     |   |o     ||     o|   |     |  []       |
   |           |  _  |   |     _||_     |   |  _  |           |
   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |
   |           |     |   |     (||)     |   |     |           |
   |           |     |   |      ||      |   |     |           |
 /''           |     |   |o     ||     o|   |     |           ''\
[_____________[_______]--'------''------'--[_______]_____________]
)";
    cout << "\nConheces?" << endl;
    cout << "\nPois... E aqui que tudo comeca... \nEsta e a tua casa, o DEIS\nOnde vais passar muitos anos a aprender e descobrir maneiras de expandir o teu territorio!";
    cout << "\nEm cada jogo vais ter 2 anos, e com isto 12 turnos, onde podes fazer as mais variadas coisas para expandir o territorio e conseguires uma pontuacao superior a dos teus demais.";
    cout << "\nTodos nos gostamos de jogos competitivos, certo? vieste parar ao certo!";
    pause();
    jogo(true);
}

void carrega() {
    bool sucesso = false;
    ClasseComandos ClasseComandosMain;
    bool loop = false;
    clear();
    do
    {
        cout << "Qual e o nome do imperio que queres carregar? ";
        string nomefich;
        if (loop == false) {
            cin.ignore(1000, '\n');
        }
        getline(cin, nomefich);
        VariaveisImportantes::nomeficheiro = nomefich;
        string nLinhas, operacao;
        ifstream OpenFile(nomefich + ".save");

        if (OpenFile.is_open())
        {
            cout << "\nBem-vindo de volta! Eis os comandos introduzidos anteriormente:\n\n" << endl;
            while (!OpenFile.eof()) {
                getline(OpenFile, nLinhas);
                cout << nLinhas << endl;
                if (!nLinhas.empty())
                {
                    operacao = nLinhas;
                    SeparaPalavras(operacao, true);
                }
            }
            cout << "Ficheiro carregado com sucesso!" << endl;
            OpenFile.close();
            sucesso = true;
        }
        else {
            loop = true;
            cout << "\n>>> ERRO A CARREGAR O FICHEIRO!!! <<<" << endl;
        }

    } while (sucesso == false);


    jogo(false);
}

void mainmenu() {

	cout << R"(
           %%%%%%%%%%%%                                                         
       %%%%%%%%%%%%%%%%%%%%                                                 
     %%%%%%%%%%%%%%%%%%%%%%%%                                                   
   #%%%%%%%%%%%    %%%%%%%%%%%        %%%%  %%%%%%%%%%   %%%%%%%%%   %%%%%%%%%  
  .%%%%%%%%%          %%%%%%%%%       %%%%  %%%%}       %%%____%%%% %%%%     
  %%%%%%%%%            %%%%%%%%%      %%%%      {%%%%%  %%%         %%%%     
  %%%%%%%%%            %%%%%%%%%      %%%%  #%%%%%%%%%   %%%%%%%%%   %%%%%%%%%. 
  %%%%%%%%%            %%%%%%%%%                                                
  %%%%%%%%%            %%%%%%%%%                                               
  %%%%%%%%%            %%%%%%%%%      ISEC
  %%%%%%%%%            %%%%%%%%%                           I See, Eu Conquisto!

     by the greatest devs Joao 'FXVNDER' Oliveira and Ze 'EdEquinox' Marques
                      >>> 2018012875              >>> 2018019295

     Vamos comecar a nossa aventura? Ou ja comecaste o grind?
            1 - Novo mundo // 2 - Carrega mundo                        
)";

}

void programa() {
	int operacao;
	bool start = false;
	mainmenu();
	while (start == false) {
		cout << "               >> ";
		cin >> operacao;
		if (operacao == 1) {
			start = true;
			inicio();
		}
		else if (operacao == 2) {
			start = true;
			carrega();
		}
		else cout << "           Acho que te enganaste, amigo... Mas eu dou-te outra chance! \n";
	}
}

#pragma region codigo testes

//#include <list>
//list<int> dest(Imperio.begin(), Imperio.end());
//cout << "Conteudo do vetor Imperio:\n";
//for (const int& i : dest) {
//	cout << i << " " << endl;
//}
//
//list<int> dest(Mundo.begin(), Mundo.end());
//cout << "Conteudo do vetor Mundo:\n";
//for (const int& i : dest) {
//	cout << i << " " << endl;
//}


//#pragma region Vetores (DEPOIS MOVER)
//
//vector<ClasseTerritorios> vetorMundo(vector <ClasseTerritorios> Mundo) {
//	
//	return Mundo;
//}
//
//vector<ClasseTerritorios> vetorImperio(vector <ClasseTerritorios> Imperio) {
//	
//	return Imperio;
//}
//
//#pragma endregion

        // if (nomeficheiro.find(' ') || nomeficheiro.find('ç') || nomeficheiro.find('á') || nomeficheiro.find('?'))
        // cout << "\nO ficheiro nao pode ter espacos ou simbolos no nome!" << endl;

        // cout << RemoverEspacos(nomeficheiro);

    //codigo pode vir a ser util:
    // for (unsigned int i = 0; i < VectorComandos.size(); i++) {
    // cout << VectorComandos[i] << endl;
    // }

    //{
    //	if (tipo == vetores::Mundo[x].NomeTerritorio)
    //	{
    //		i++;
    //		ntipoNovo++;
    //	}
    //}

    // if ntipo > 1, tipo = +s

#pragma endregion

