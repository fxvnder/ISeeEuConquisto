#pragma region Includes e NS

#include "comando.h"
#include "includes.h"
#include "territorios.h"
#include "tecnologias.h"
#include "menus.h"

using namespace std;
using namespace TerritoriosNS;
using namespace ComandosNS;

namespace vetores
{
 // CLASSE PARA INCORPORAR vv
	vector<ClasseTerritorios> Mundo;
	vector<ClasseTerritorios> Imperio;
}

namespace OutVars
{
    string username, nomeficheiro; // apenas serve para armazenar miscelaneas
    int QuantCria = -1, QuantCastelo = -1, QuantDuna = -1, QuantFortaleza = -1, QuantMina = -1, QuantMontanha = -1, QuantPlanicie = -1; // Territorios Criados
    int turno = 1, cofre = 0, armazem = 0, limitecofre = 5, limitearmazem = 5, militar = 0, limitemilitar = 3, bolsa = 0, defesa = 0; // Misc.
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



#pragma region MENUS

void mainmenu() {

    MainMenuASCII();

}

void inicio() {
    string operacao;
    clear();
    cout << "Bem vindo a aventura, amigo, bem-haja! Vamos comecar?...\n";
    cout << "\n...espera la... ainda nem sei o teu nome!...";
    cout << "\n\nEntao? Como te chamas?";
    cout << "\n\nInserir Nickname: ";
    cin.ignore(1000, '\n');
    getline(cin, OutVars::username);
    cout << "\n" << OutVars::username << "... e isso? Prazer em conhecer-te!";
    cout << "\nBem, vieste em boa altura, estamos mesmo a precisar de uma maozinha aqui... Junta-te a nos!";
    pause();
    clear();
    CasteloASCII();
    cout << "\nConheces?" << endl;
    cout << "\nPois... E aqui que tudo comeca... \nEsta e a tua casa, o DEIS\nOnde vais passar muitos anos a aprender e descobrir maneiras de expandir o teu territorio!";
    cout << "\nEm cada jogo vais ter 2 anos, e com isto 12 turnos, onde podes fazer as mais variadas coisas para expandir o territorio e conseguires uma pontuacao superior a dos teus demais.";
    cout << "\nTodos nos gostamos de jogos competitivos, certo? Vieste parar ao certo!";
    pause();
    jogo(true);
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

void ComandosJogo(string operacoes, int bolsa)
{
}

void jogo(bool PrimeiraVez) {
    ClasseComandos ClasseComandosMain;
    string operacao;
    string StringIndividual;
    vector<ClasseTerritorios> Mundo;
    ofstream SaveFile;
    int OJOGOVAICOMECAR = 0;

    if (PrimeiraVez == true) {
        clear();

        BemVindoAoISECText();

        getline(cin, OutVars::nomeficheiro);

        cout << "\nAviso: O teu ficheiro foi gravado como " << OutVars::nomeficheiro << ".save" << endl;
        ClasseComandosMain.GravaFicheiro(OutVars::nomeficheiro);
        SeparaPalavras("nickname " + OutVars::username, false);
        cout << "\n\n\nParabens, " << OutVars::username << "! Vamos agora comecar a jogar! Para sair escreve sair" << endl;
        cout << ">>> comandos disponiveis: cria / lista / nickname / ajuda / sair\n>>>>> Se te sentires preparado para comecar o jogo escreve comecar" << endl;
        
        do
        {
            cout << "Insira um comando aqui: ";

            getline(cin, operacao);

            if (operacao == "comecar")
            {
                OJOGOVAICOMECAR = 1;
                operacao = "sair";
            }

            if (operacao.empty()) {
                cout << "\nTens de dizer um comando, amigo" << endl;
            }
            
            else SeparaPalavras(operacao, false);

        } while (operacao != "sair");

        if (OJOGOVAICOMECAR == 1)
        {
            clear();
            GameOn();

        }

        SaveFile.close();

    }
    else
    {
        cout << "Bem vindo de volta, " << OutVars::username;
        do
        {
            cout << "\nInsira um comando aqui: ";

            getline(cin, operacao);

            if (operacao == "comecar")
            {
                OJOGOVAICOMECAR = 1;
                operacao = "sair";
            }

            if (operacao.empty()) {
                cout << "\nPor favor escreva alguma coisa" << endl;
            }
            else
            {
                SeparaPalavras(operacao, false);
            }

        } while (operacao != "sair");

        if (OJOGOVAICOMECAR == 1)
        {
            clear();
            GameOn();

        }

        SaveFile.close();
    }

}

#pragma endregion



#pragma region PRE-JOGO

void pause() { // PAUSA EM PRINTS
    cin.ignore();
    cin.get();
}

#pragma region CRIA

void ComandoCria(string tipo, int ntipo) {

    // este código tá lindo oh https://media.tenor.com/images/7f0508ab7d5b50e6f93c2b5439b4eb5a/tenor.gif
    
    if (tipo == "fortaleza") {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantFortaleza++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "fortaleza";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantFortaleza;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "fortaleza" + to_string(OutVars::QuantFortaleza + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 8;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 0;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 0;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
        //CriaFortaleza(OutVars::QuantFortaleza, ntipo);
    }
    else if (tipo == "castelo")
    {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantCastelo++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "castelo";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantCastelo;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "castelo" + to_string(OutVars::QuantCastelo + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 7;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 1;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 3;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
    }
    else if (tipo == "duna")
    {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantDuna++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "duna";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantDuna;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "duna" + to_string(OutVars::QuantDuna + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 4;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 0;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 1;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
    }
    else if (tipo == "planicie")
    {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantPlanicie++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "planicie";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantPlanicie;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "planicie" + to_string(OutVars::QuantPlanicie + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 5;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 1;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 1;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
    }
    else if (tipo == "mina")
    {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantMina++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "mina";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantMina;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "mina" + to_string(OutVars::QuantMina + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 5;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 1;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 0;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
    }
    else if (tipo == "montanha")
    {
        for (int i = 0; i < ntipo; i++)
        {
            OutVars::QuantMontanha++; OutVars::QuantCria++;
            vetores::Mundo.push_back(ClasseTerritorios());
            vetores::Mundo[OutVars::QuantCria].Tipo = "montanha";
            vetores::Mundo[OutVars::QuantCria].IDTerr = OutVars::QuantMontanha;
            vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "montanha" + to_string(OutVars::QuantMontanha + 1);
            vetores::Mundo[OutVars::QuantCria].Resistencia = 6;
            vetores::Mundo[OutVars::QuantCria].ProdOuro = 0;
            vetores::Mundo[OutVars::QuantCria].ProdProdutos = 1;
            vetores::Mundo[OutVars::QuantCria].Pontos = 1;
            cout << "Foi criado " << vetores::Mundo[OutVars::QuantCria].NomeTerritorio << endl;
        }
    }
    else {
        cout << "Esse tipo de terreno nao existe, amigo! Tenta de novo um dos seguintes:\nfortaleza / castelo / duna / planicie / mina / montanha" << endl;
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
        OutVars::nomeficheiro = nomefich;
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
        if (VectorComandos[1] == "" || VectorComandos[2] == "" || VectorComandos[1].size() == 0 || VectorComandos[2].size() == 0)
        {
            cout << "Operacao invalida! Tenta novamente! Usa o comando ajuda se precisares!" << endl;
        }
        else
        {
            stringstream Tamanho(VectorComandos[2]);
            int SeguraInt = 0;
            Tamanho >> SeguraInt;
            ClasseComandosMain.CriaTerreno(VectorComandos[1], SeguraInt);
            if (ler == false) {
                ofstream SaveFile;
                SaveFile.open(OutVars::nomeficheiro + ".save", ios::out | ios_base::app);
                SaveFile << VectorComandos[0] << " " << VectorComandos[1] << " " << VectorComandos[2] << endl;
            }
        }
    }
    else if (VectorComandos[0] == "lista")
    {
        if (VectorComandos.size() > 1) {
            ClasseComandosMain.ListaComando(VectorComandos[1]);
        }
        else
        {
            ClasseComandosMain.ListaComandosBeforeGame();
        }
    }
    else if (VectorComandos[0] == "nickname")
    {
        OutVars::username = VectorComandos[1];
        if (ler == true) cout << "\nO teu nickname: " << VectorComandos[1] << endl;
        if (ler == false) {
            ofstream SaveFile;
            SaveFile.open(OutVars::nomeficheiro + ".save", ios::out | ios_base::app);
            SaveFile << VectorComandos[0] << " " << VectorComandos[1] << endl;
        }
    }
    else if (VectorComandos[0] == "ajuda")
    {
        clear();
        AjudaPreJogo();

    }
    else if (VectorComandos[0] == "sair") cout << "\n\n\nBye bye!" << endl;
    else cout << "\nComando " << VectorComandos[0] << " nao reconhecido." << endl;
}

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

void ComandoListaMundoInd(vector<ClasseTerritorios> const& Mundo, string territorio) {
    int found = 0;
    for (int i = 0; i < Mundo.size(); i++) {
        if (Mundo.at(i).NomeTerritorio == territorio)
        {
            cout << ">>> TERRITORIO ENCONTRADO <<<";
            cout << "\nNome do territorio: " << Mundo.at(i).NomeTerritorio << endl;
            cout << "Resistencia do territorio: " << Mundo.at(i).Resistencia << endl;
            cout << endl;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Territorio nao encontrado..." << endl;
    }
}

void ComandosNS::ClasseComandos::ListaComandosBeforeGame()
{
    cout << "\n\n>>> TERRITORIOS CRIADOS <<<\n" << endl;
    ComandoListaMundo(vetores::Mundo);
    cout << endl;
}

void ComandosNS::ClasseComandos::ListaComandosAfterGame()
{
    cout << "\n\n>>> TERRITORIOS CRIADOS <<<\n" << endl;
    ComandoListaMundo(vetores::Mundo);
    cout << "\n\n>>> TERRITORIOS CONQUISTADOS <<<\n" << endl;
    ComandoListaImperio(vetores::Imperio);
    cout << endl;
}

void ComandosNS::ClasseComandos::ListaComando(string territorio)
{
    ComandoListaMundoInd(vetores::Mundo, territorio);
    cout << endl;
}

string ComandosNS::ClasseComandos::getTerritorio()
{
    return string();
}
#pragma endregion

void Eventos()
{
    int randevento = rand() % 4;
    if (randevento == 0) {
        cout << "\nOra ora, foi encontrado um recurso perdido! Que sorte!" << endl;
        LostRecurso();
    }
    else if (randevento == 1) {
        cout << "\nOh nao, estas a ser invadido" << endl;
        int fatorsorte = rand() % 6 + 1;
        int invasao = 0;
        size_t tamanho = vetores::Imperio.size();
        int resistenciatemp = vetores::Imperio[tamanho - 1].Resistencia;
        if (OutVars::turno < 7)
        {
            
            invasao = 2 + fatorsorte;
                if (resistenciatemp + OutVars::defesa > invasao)
                {
                    
                    cout << "\nUfa, que alivio, a invasao falhou" << endl;
                }
                else
                {
                    vetores::Imperio.pop_back();
                    cout << "\nOra bolas, a invasao foi bem sucedida" << endl;
                }
        }
        else {
            
            invasao = 3 + fatorsorte;
            if (resistenciatemp + OutVars::defesa > invasao)
            {
                
                cout << "\nUfa, que alivio, a invasao falhou" << endl;
            }
            else
            {
                vetores::Imperio.pop_back();
                cout << "\nOra bolas, a invasao foi bem sucedida" << endl;
            }
        }
        
    }
    else if (randevento == 2) {
        cout << "\nUrra! Assinaste uma alianca com um imperio vizinho" << endl;
        OutVars::militar++;
        if (OutVars::militar > OutVars::limitemilitar)
        {
            OutVars::militar = OutVars::limitemilitar;
        }
        cout << "\nA tua forca militar e agora " << OutVars::militar << "!" << endl;
    }
    else if (randevento == 3) {
        cout << "\nDia calmo amigo, podes descansar" << endl;
    }
}

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
            cin.ignore();
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
                    cout << "Parabens! Conquistou o " << vetores::Mundo[i].NomeTerritorio << "! O seu fator sorte vitorioso foi de " << FatorSorte << "%" << endl;
                    Recolher();
                    Eventos();
                    if (OutVars::cofre > OutVars::limitecofre)
                    {
                        OutVars::cofre = OutVars::limitecofre;
                        cout << "$$$$$ Cofre cheio! $$$$$" << endl;
                    }
                    if (OutVars::armazem > OutVars::limitearmazem)
                    {
                        OutVars::armazem = OutVars::limitearmazem;
                        cout << "$$$$$ Armazem cheio! $$$$$" << endl;
                    }
                    ProximoTurno();
                    cout << "Faz enter para continuar para o proximo turno...";
                    cin.ignore();
                }
                else
                {
                    cout << "Que azar! O territorio " << vetores::Mundo[i].NomeTerritorio << " nao foi conquistado, pois o seu fator sorte foi de " << FatorSorte << "%" << endl;
                    Recolher();
                    Eventos();
                    if (OutVars::cofre > OutVars::limitecofre)
                    {
                        OutVars::cofre = OutVars::limitecofre;
                        cout << "$$$$$ Cofre cheio! $$$$$" << endl;
                    }
                    if (OutVars::armazem > OutVars::limitearmazem)
                    {
                        OutVars::armazem = OutVars::limitearmazem;
                        cout << "$$$$$ Armazem cheio! $$$$$" << endl;
                    }
                    ProximoTurno();
                    cout << "Faz enter para continuar para o proximo turno...";
                    cin.ignore();
                }
                
            }
        }

        if (existe == false)
        {
            cout << "Territorio nao encontrado. Acao ignorada." << endl;
            cin.ignore();
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

#pragma region PASSA

void ComandoPassaMain() {

    &ClasseComandos::nextTurno;

}

int ComandosNS::ClasseComandos::nextTurno()
{
    &ClasseComandos::getTurno;
    ClasseComandos::setTurno(turno + 1);
    return turno;

}
int ClasseComandos::setTurno(int turno)
{
    return turno;
}
int ClasseComandos::getTurno() {
    return turno;
}
#pragma endregion


#pragma endregion



#pragma region POS-JOGO

void ComandosJogo(string operacoes) { 
    vector<string> VectorComandos;
    ClasseComandos ClasseComandosMain;
    string PalavraSeparada;
    stringstream StrStream(operacoes);

    //TerritorioInicial();

    while (StrStream >> PalavraSeparada) {
        VectorComandos.push_back(PalavraSeparada);
    }

    if (VectorComandos[0] == "conquista")
    {
        stringstream Tamanho(VectorComandos[1]);
        ClasseComandosMain.ConquistaTerritorios(VectorComandos[1]);
    }
    else if (VectorComandos[0] == "lista")
    {
        if (VectorComandos.size() > 1) {
            ClasseComandosMain.ListaComando(VectorComandos[1]);
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
        else
        {
            ClasseComandosMain.ListaComandosAfterGame();
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
    }
    else if (VectorComandos[0] == "maisouro" )
    {
        if (OutVars::bolsa == 1)
        {
            if (OutVars::armazem >= 2 && OutVars::cofre + 1 <= OutVars::limitecofre)
            {
                OutVars::cofre++;
                OutVars::armazem = OutVars::armazem - 2;
            }
            else if (OutVars::cofre + 1 > OutVars::limitecofre) {
                cout << "Limite do cofre atingido" << endl;
            }
            else
                cout << "Nao tens produtos suficientes, amigo!" << endl;
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
        else
        {
            cout << "\nNao tens bolsa de valores diponivel para fazeres estra transacao, amigo!" << endl;
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
        
    }
    else if (VectorComandos[0] == "maisprod")
    {
        if (OutVars::bolsa == 1)
        {
            if (OutVars::cofre >= 2 && OutVars::armazem + 1 <= OutVars::limitearmazem)
            {
                OutVars::armazem++;
                OutVars::cofre = OutVars::cofre - 2;
            }
            else if (OutVars::armazem + 1 > OutVars::limitearmazem) {
                cout << "Limite do armazem atingido" << endl;
            }
            else
                cout << "\nNao tens ouro suficiente, amigo!" << endl;
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
        else
        {
            cout << "\nNao tens bolsa de valores diponivel para fazeres estra transacao, amigo!" << endl;
            cout << "Faz enter para continuar...";
            cin.ignore();
        }
        
    }
    else if (VectorComandos[0] == "maismilitar")
    {
        if (OutVars::cofre >= 2 && OutVars::armazem + 2 <= OutVars::limitearmazem)
        {
            OutVars::militar++;
            OutVars::cofre--;
            OutVars::armazem--;
        }
        else if (OutVars::armazem + 1 > OutVars::limitearmazem) {
            cout << "Limite do armazem atingido" << endl;
        }
        else
            cout << "\nNao tens ouro suficiente, amigo!" << endl;
        cout << "Faz enter para continuar...";
        cin.ignore();
    }
    else if (VectorComandos[0] == "passar")
    {
        
        Recolher();
        if (OutVars::cofre > OutVars::limitecofre)
        {
            OutVars::cofre = OutVars::limitecofre;
            cout << "$$$$$ Cofre cheio! $$$$$" << endl;
        }
        if (OutVars::armazem > OutVars::limitearmazem)
        {
            OutVars::armazem = OutVars::limitearmazem;
            cout << "$$$$$ Armazem cheio! $$$$$" << endl;
        }
        Eventos();
        cout << "Decidiste passar. Faz enter para ir ao proximo turno...";
        ProximoTurno();
        cin.ignore();
    }
    else if (VectorComandos[0] == "adquire")
    {
        CriaTecnologia(VectorComandos[1]);
    }
    else if (VectorComandos[0] == "ajuda")
    {
        clear();
        AjudaPosJogo();
        cout << "Faz enter para voltar ao menu.";
        cin.ignore();
    }
    else if (VectorComandos[0] == "sair") cout << "\n\n\nBye bye!" << endl;
    else {
        cout << "\nComando " << VectorComandos[0] << " nao reconhecido." << endl;
        cout << "Faz enter para voltar ao menu.";
        cin.ignore();
    }
}

void ProximoTurno()
{

    OutVars::turno++;

    if (OutVars::turno == 3)
    {
        for (int i = 0; i < vetores::Imperio.size(); i++)
        {
            if (vetores::Imperio[i].Tipo == "montanha") 
            {
                vetores::Imperio[i].ProdProdutos = 1;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " PRODUZ +1 UNIDADE DE PRODUTOS." << endl;
            }
            else if (vetores::Imperio[i].Tipo == "mina")
            {
                vetores::Imperio[i].ProdOuro = 2;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " PRODUZ 2 UNIDADES DE OURO." << endl;
            }
            else if (vetores::Imperio[i].Tipo == "castelo")
            {
                vetores::Imperio[i].ProdProdutos = 0;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " NAO PRODUZ PRODUTOS." << endl;
            }
        }
    }
    if (OutVars::turno == 6){
    for (int i = 0; i < vetores::Imperio.size(); i++)
        {
            if (vetores::Imperio[i].Tipo == "planicie") 
            {
                vetores::Imperio[i].ProdProdutos = 2;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " PRODUZ +1 UNIDADE DE PRODUTOS." << endl;
            }
            else if (vetores::Imperio[i].Tipo == "mina")
            {
                vetores::Imperio[i].ProdOuro = 2;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " PRODUZ 2 UNIDADES DE OURO." << endl;
            }
        }
    }
    if (OutVars::turno == 9) {
        for (int i = 0; i < vetores::Imperio.size(); i++)
        {
            if (vetores::Imperio[i].Tipo == "mina") 
            {
                vetores::Imperio[i].ProdOuro = 1;
                cout << "\nAVISO: AGORA " << vetores::Imperio[i].NomeTerritorio << " PRODUZ APENAS 1 UNIDADE DE OURO." << endl;
            }
        }
    }
}

void Recolher()
{
    for (int i = 0; i < vetores::Imperio.size(); i++)
    {
        //if (OutVars::cofre <= OutVars::limitecofre)
           OutVars::cofre = OutVars::cofre + vetores::Imperio[i].ProdOuro;
        //if (OutVars::cofre > OutVars::limitecofre)
        //{
        //    OutVars::cofre = OutVars::limitecofre;
        //    cout << "$$$$$ Cofre cheio! $$$$$" << endl;
        //}
        //
        //if (OutVars::armazem <= OutVars::limitearmazem)
            OutVars::armazem = OutVars::armazem + vetores::Imperio[i].ProdProdutos;
        //if (OutVars::armazem > OutVars::limitearmazem)
        //{
        //    OutVars::armazem = OutVars::limitearmazem;
        //    cout << "$$$$$ Armazem cheio! $$$$$" << endl;
        //}
    }
}

void TerritorioInicial() {
    OutVars::QuantCria++;
    vetores::Mundo.push_back(ClasseTerritorios());
    vetores::Mundo[OutVars::QuantCria].NomeTerritorio = "DEIS";
    vetores::Mundo[OutVars::QuantCria].IDTerr = 0;
    vetores::Mundo[OutVars::QuantCria].Pontos = 0;
    vetores::Mundo[OutVars::QuantCria].Resistencia = 9;
    vetores::Mundo[OutVars::QuantCria].ProdOuro = 1;
    vetores::Mundo[OutVars::QuantCria].ProdProdutos = 1;
    vetores::Mundo[OutVars::QuantCria].Tipo = "Territorio Inicial";
    for (int i = 0; i < vetores::Mundo.size(); i++)
    {
        if (vetores::Mundo[i].NomeTerritorio == "DEIS") {
            vetores::Imperio.push_back(vetores::Mundo[i]);
        }
    }
    
}



void LostRecurso()
{
    if (OutVars::turno < 7 && OutVars::armazem <= OutVars::limitearmazem)
        OutVars::armazem++;
    else if (OutVars::turno > 6 && OutVars::cofre <= OutVars::limitecofre)
        OutVars::cofre++;
}

void CriaTecnologia(string tecnologia) {

    if (tecnologia == "forcamilitar")
    {
       
        if (OutVars::cofre >= 1 && OutVars::armazem >= 1)
        {
            OutVars::militar++;
            cout << "Adquiriu forca militar! Passou a ser " << OutVars::militar << "!"<< endl;
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }

    if (tecnologia == "drones")
    {
        CriaDrones();
        if (OutVars::cofre >= 3)
        {
            OutVars::cofre = OutVars::cofre - 3;
            OutVars::limitemilitar = 5;
            cout << "Adquiriu drones! Agora o limite miliar e de 5." << endl;
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }
    else if (tecnologia == "misseis")
    {
        CriaMisseis();
        if (OutVars::cofre >= 4)
        {
            OutVars::cofre = OutVars::cofre - 4;
            cout << "Adquiriu misseis!" << endl;
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }
    else if (tecnologia == "defesas")
    {
        CriaDefesas();
        if (OutVars::cofre >= 4)
        {
            OutVars::cofre = OutVars::cofre - 4;
            OutVars::defesa = 1;
            cout << "\nAcabaste de adquirir uma unidade de defesa!";
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }
    else if (tecnologia == "bolsa")
    {
        CriaBolsa(OutVars::bolsa);
        if (OutVars::cofre >= 2)
        {         
            OutVars::cofre = OutVars::cofre - 2;
            OutVars::bolsa = 1;
            cout << "\nAcabaste de adquirir a bolsa de valores, podes agora trocar produtos e ouro" << endl;
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }
    else if (tecnologia == "banco")
    {
        CriaBanco();
        if (OutVars::cofre >= 3)
        {
            OutVars::cofre = OutVars::cofre - 3;
            OutVars::limitecofre = 5;
            OutVars::limitearmazem = 5;
            cout << "Compraste o banco centra! Podes agora armazenar mais recursos" << endl;
            cin.ignore();
        }
        else
        {
            cout << "Nao tem dinheiro para comprar esta tecnologia." << endl;
            cout << "Faz enter para voltar ao menu.";
            cin.ignore();
        }
    }
    else
    {
        cout << "Essa tecnologia nao existe, logo nao foi comprada. Tenta novamente." << endl;
        cout << "Tecnologias disponiveis: drones / misseis / defesas / bolsa / banco";
        cin.ignore();
    }
}


void GameOn() {
    ClasseComandos ClasseComandosMain;
    string comandoJ;
    clear();
    GameONMenu();
    pause();
    TerritorioInicial();
    do
    {

        clear();
        CasteloTurnos();
        cout << ">>>>> TURNO " << OutVars::turno << " <<<<<" << endl;
        if (OutVars::turno < 7) {
            cout << ">>>>>  ANO  1 <<<<<" << endl;
        }
        if (OutVars::turno >= 7)
        {
            cout << ">>>>>  ANO  2 <<<<<" << endl;
        }
        if (OutVars::turno == 12) {
            int sumpontos = 0;
            for (int i = 0; i < vetores::Imperio.size(); i++)
            {
                sumpontos = sumpontos + vetores::Imperio[i].Pontos;
            }
            cout << "\n\nParabens! Concluiste o jogo com " << sumpontos << " pontos!\nEspero voltar a ver-te em breve, conquistador! :)";
            cin.ignore();
            break;
        }
         
        cout << "Cofre: " << OutVars::cofre << " Armazem: " << OutVars::armazem << endl;
        cout << "\n\nO que pretendes fazer este turno?\n>> conquista / adquire / eventos / passar / maisouro / maisprod\n> Outros comandos: lista / ajuda / sair\n" << endl;

        getline(cin, comandoJ);

        if (comandoJ.empty()) {
            cout << "\nTens de dizer um comando, amigo" << endl;
        }
        else
        {
            
            ComandosJogo(comandoJ);
        }
      

    } while (comandoJ != "sair" );
    

}

#pragma endregion


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

