#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
enum Cor { BRANCO, CINZA, PRETO };

class Grafo {
public:
    int vertices;
    int arestas;
    vector<vector<int>> adj;
    vector<int> cor;
    vector<int> verticesCorte;

    Grafo(int v, int a);
    void adicionaAresta(int u, int v);
    void imprimiListaAdj();
    bool ehConexo(int ini, int r1, int r2);
    void dfs(int v);
    int conexidadeVertices();
    void removeVertice(int v);
    void imprimiVerticesCorte(int conexidade);
};

