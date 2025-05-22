#include "Grafo.hpp"

Grafo::Grafo(int v, int a){
    vertices = v;
    arestas = a;
    adj.resize(v);
    cor.resize(v, BRANCO);
}

void Grafo::adicionaAresta(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void Grafo::dfs(int v){
    cor[v] = CINZA;
    for(int vizinho: adj[v]){
        if(cor[vizinho] == BRANCO){
            dfs(vizinho);
        }
    }
    cor[v] = PRETO;
}

bool Grafo::ehConexo(){
    cor.assign(vertices, BRANCO);

    dfs(0);

    for(int i = 0; i < vertices; i++){
        if(cor[i] == BRANCO){
            return false;
        }
    }
    return true;
}

void Grafo::imprimiListaAdj(){
    cout << "Lista de Adjacencia:" << endl;
    for(int i = 0; i < vertices; i++){
        cout << i << "->";
        for(int con : adj[i]){
            cout << con << " ";
        }
        cout << endl;
    }
}