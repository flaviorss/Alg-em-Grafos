#include <iostream>
#include <vector>
#include "Grafo.hpp"

using namespace std;

int main(){

    int n; //nº de vertices
    int m; //nº de arestas
    int u, v;
    cin >> n >> m;

    Grafo grafo(n, m);

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        grafo.adicionaAresta(u, v);
    }

    grafo.imprimiListaAdj();

    if(grafo.ehConexo()){
        cout << "Grafo conexo" << endl;
    }else{
        cout << "Grafo desconexo" << endl;
    }

    return 0;
}