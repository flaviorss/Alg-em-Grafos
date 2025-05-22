#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Grafo {
public:
    int vertices;
    int arestas;
    vector<vector<int>> adj;

    Grafo(int v, int a);
    void adicionaAresta(int u, int v);
    void imprimiListaAdj();
};

