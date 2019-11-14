#include "linha.cpp"
#include "cabecalho.cpp"
#include "grafo.cpp"
#include <string.h>
#include <string>
#include <vector>

#define MAX_VERTICES 30
#define INFINITO 9999
#define PROIBIDO 666
using namespace std;

void montarLinhas(int *vetor, string linha){
	int pos, tam;

    pos = linha.find(" ", 0);
	vetor[0] = stoi(linha.substr(0, pos));

    tam = pos+1;
    pos = linha.find(" ", pos+1);
    vetor[1] = stoi(linha.substr(tam, pos-tam));

    tam = pos+1;
    pos = linha.find(" ", pos+1);
    vetor[2] = stoi(linha.substr(tam, pos-tam));
}

void prepararLinhas(Linha *linhas[], string arquivo, Cabecalho *cabecalho){
	string line;
	ifstream myfile(arquivo);


	if (myfile.is_open())
	{
		getline(myfile, line);
		cabecalho->tamanho = stoi(line);

		getline(myfile, line);
		cabecalho->inicio = stoi(line);

		getline(myfile, line);
		cabecalho->fim = stoi(line);

		int i=0;
		while (!myfile.eof())
		{
			int *vet;
			vet = new int[3];
			getline(myfile, line);
			montarLinhas(vet, line);
			
			linhas[i++] = new Linha(vet[0], vet[1], vet[2]);
		}

		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}

int main()
{
	cout << "inicio da execucao" << endl;
	Linha *linhas[INFINITO];
	int resultado[INFINITO];
	Cabecalho *cabecalho = new Cabecalho();

	for(int i=0; i<INFINITO+1; i++){
		linhas[i] = new Linha();
		resultado[i] = PROIBIDO;
	}
    
    grafo grafo;

	prepararLinhas(linhas, "lab1.txt", cabecalho);

	grafo.montagem(cabecalho->tamanho, linhas);

	grafo.dijkstra(cabecalho->inicio, cabecalho->fim, resultado);

	int i=0;
	while(resultado[i] != PROIBIDO){
		if(resultado[i] != cabecalho->fim){
			cout << resultado[i++] << " --> ";
		} else {
			cout << resultado[i++] << endl;
		}
	}

	cout << "fim da execução" << endl;

	exit(1);
	
}