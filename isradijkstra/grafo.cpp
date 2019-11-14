#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

#define MAX_VERTICES 30
#define INFINITO 9999
using namespace std;

struct vertice
{
    bool adjacencia;
    int distancia;
};

class grafo
{
  public:
    int num_vertices;
    int inicio;
    int fim;
    struct vertice vertices[MAX_VERTICES][MAX_VERTICES];

    grafo();
    void montagem(int tamanho, Linha *linhas[]);
    void dijkstra(int inicio, int fim, int resultado[]);
};

grafo::grafo()
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            if (j == i)
            {
                vertices[i][j].adjacencia = true;
                vertices[i][j].distancia = 0;
            }
            else
            {
                vertices[i][j].adjacencia = false;
                vertices[i][j].distancia = INFINITO;
            }
        }
    }
}

void grafo::montagem(int tamanho, Linha *linhas[])
{
    for(int i=0; i<tamanho-1; i++){
        vertices[linhas[i]->esquerda][linhas[i]->direita].adjacencia = true;
        vertices[linhas[i]->esquerda][linhas[i]->direita].distancia = linhas[i]->valor;
    }
}

void grafo::dijkstra(int inicio, int fim, int resultado[])
{
    cout << "calculando solucoes..." << endl;
    int distancia[MAX_VERTICES];
    int vst[MAX_VERTICES];
    int caminho[MAX_VERTICES];
    int atual, k, dc, menor, nova;

    for (int i = 0; i < MAX_VERTICES; ++i)
    {
        vst[i] = false;
        distancia[i] = INFINITO;
    }

    vst[inicio] = true;
    distancia[inicio] = 0;
    atual = inicio;
    k = atual;

    int sair = 0;
    while (atual != fim)
    {
        menor = INFINITO;
        dc = distancia[atual];
        for (int i = 0; i < MAX_VERTICES; ++i)
        {
            if (vst[i] == false)
            {
                nova = dc + vertices[atual][i].distancia;
                if (nova < distancia[i])
                {
                    distancia[i] = nova;
                    caminho[i] = atual;
                }
                if (distancia[i] < menor)
                {
                    menor = distancia[i];
                    k = i;
                }
            }
            
        }
        
        atual = k;
        vst[atual] = true;
        sair++;
        if(sair > INFINITO){
            cout << "destino nao encontrado" << endl;
            exit(1);
        }
    }
    
    int prc = fim;
    vector<int> sequencia;
    sequencia.reserve(MAX_VERTICES);

    while (prc != inicio)
    {
        sequencia.push_back(caminho[prc]);
        prc = caminho[prc];
    }
    
    int indice=0;
    resultado[indice++]=inicio;
    if (sequencia.rbegin() != sequencia.rend())
    {
        for(vector<int>::reverse_iterator i = sequencia.rbegin(); ++i != sequencia.rend(); )
        {
            resultado[indice++] = *i;
        }
    }
    resultado[indice]=fim;
}