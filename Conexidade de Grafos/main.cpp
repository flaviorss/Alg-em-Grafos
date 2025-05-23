#include <iostream>
#include <vector>
#include <stack>
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

    //grafo.imprimiListaAdj();
    
    if(grafo.ehConexo(0, -1, -1)){
        switch (grafo.conexidadeVertices()){
        case 1:
            cout << "Grafo 1-conexo." << endl;
            grafo.imprimiVerticesCorte(1);
            break;
        case 2:
            cout << "Grafo 2-conexo." << endl;
            grafo.imprimiVerticesCorte(2);
            break;
        case 3:
            cout << "Grafo 3-conexo." << endl;
            break;
        default:
            break;
        }
    }else{
        cout << "Grafo desconexo." << endl;
    }

    return 0;
}