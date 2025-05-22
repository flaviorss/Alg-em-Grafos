#pragma once
#include <iostream>
#include <vector>

using namespace std;
enum Cor { BRANCO, CINZA, PRETO };

class Grafo {
public:
    int vertices;
    int arestas;
    vector<vector<int>> adj;
    vector<int> cor;

    Grafo(int v, int a);
    void adicionaAresta(int u, int v);
    void imprimiListaAdj();
    bool ehConexo();
    void dfs(int v);
};

