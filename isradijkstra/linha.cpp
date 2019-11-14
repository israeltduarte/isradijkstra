#include <iostream>

using namespace std;

class Linha
{
public:
    int esquerda;
    int direita;
    int valor;

    Linha(int esquerda, int direita, int valor);
    Linha();
    void imprime();
};

Linha::Linha()
{
    this->esquerda = 666;
    this->direita = 666;
    this->valor = 666;
}

Linha::Linha(int esquerda, int direita, int valor)
{
    this->esquerda = esquerda;
    this->direita = direita;
    this->valor = valor;
}

void Linha::imprime(){
    cout << this->esquerda << "-" << this->direita <<  "-" << this->valor << endl;
}
