#include "territorios.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class territorios {

    int tamanho;

public:
    territorios(int tamanho) : tamanho(tamanho){
    cout << "Territorio criado..." << endl;
    };

    ~territorios(){
        cout << "Territorio apagado..." << endl;
    }

    string toString(){
        return to_string(tamanho);
    }
};

