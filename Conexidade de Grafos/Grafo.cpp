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