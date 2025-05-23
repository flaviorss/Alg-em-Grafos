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

/*void Grafo::dfs(int v){
    cor[v] = CINZA;
    for(int vizinho: adj[v]){
        if(cor[vizinho] == BRANCO){
            dfs(vizinho);
        }
    }
    cor[v] = PRETO;
}*/

void Grafo::dfs(int v) {
    stack<int> pilha;
    pilha.push(v);
    cor[v] = CINZA;

    while (!pilha.empty()) {
        int u = pilha.top();
        bool terminou = true;

        for (int vizinho : adj[u]) {
            if (cor[vizinho] == BRANCO) {
                cor[vizinho] = CINZA;
                pilha.push(vizinho);
                terminou = false;
                break; 
            }
        }

        if (terminou) {
            pilha.pop();
            cor[u] = PRETO;
        }
    }
}

bool Grafo::ehConexo(int ini, int r1, int r2){
    cor.assign(vertices, BRANCO);

    dfs(ini);

    for(int i = 0; i < vertices; i++){
        if(cor[i] == BRANCO && i != r1 && i != r2){
            return false;
        }
    }
    return true;
}

int Grafo::conexidadeVertices(){
    int ini, conexidade;
    //Verifica conexidade 1
    for(int v = 0; v < vertices; v++){
        Grafo temp = *this; //Realiza cópia do grafo
        temp.removeVertice(v);
        
        v == 0 ? ini = 1 : ini = 0;
        if(!temp.ehConexo(ini, v, v)){
            verticesCorte.push_back(v);
            conexidade = 1;
        }
    }
    if(conexidade == 1){return 1;}

    //Verifica conexidade 2
    for(int v1 = 0; v1 < vertices; v1++){
        for(int v2 = v1+1; v2 < vertices; v2++){
            Grafo temp = *this;
            temp.removeVertice(v1);
            temp.removeVertice(v2);

            if(v1 == 0){
                if(v2 == 1){
                    ini = 2;
                }else{ ini = 1; }
            }else{ ini = 0; }

            if(!temp.ehConexo(ini, v1, v2)){
                verticesCorte.push_back(v1);
                verticesCorte.push_back(v2);
                conexidade = 2;
            }
        }
    }
    if(conexidade == 2){return 2;}

    return 3; //Conexidade >= 3

}

void Grafo::removeVertice(int v){

    for (int u : adj[v]) {
        // Remove v da lista de adjacência de cada vizinho u
        auto& vizinhos_u = adj[u];
        for (auto it = vizinhos_u.begin(); it != vizinhos_u.end(); ) {
            if (*it == v) {
                it = vizinhos_u.erase(it);
            } else {
                ++it;
            }
        }
    }
    adj[v].clear();

}

void Grafo::imprimiVerticesCorte(int conexidade){
    if(conexidade == 1){
        for (int i = 0; i < verticesCorte.size(); i++){
            cout << verticesCorte[i] << endl;
        }
    }else{
        for (int i = 0; i < verticesCorte.size(); i+=2){
            cout << verticesCorte[i] << " " << verticesCorte[i+1] << endl;
        }
    }
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