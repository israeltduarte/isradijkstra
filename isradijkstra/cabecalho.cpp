#include <iostream>

using namespace std;

class Cabecalho
{
public:
    int tamanho;
    int inicio;
    int fim;

    Cabecalho(int tamanho, int inicio, int fim);
    Cabecalho();
    void imprime();
};

Cabecalho::Cabecalho()
{
    this->tamanho = 666;
    this->inicio = 666;
    this->fim = 666;
}

Cabecalho::Cabecalho(int tamanho, int inicio, int fim)
{
    this->tamanho = tamanho;
    this->inicio  = inicio;
    this->fim = fim;
}

void Cabecalho::imprime(){
    cout << "Dados do cabecalho: " << this->tamanho << "-" << this->inicio  <<  "-" << this->fim << endl;
}
