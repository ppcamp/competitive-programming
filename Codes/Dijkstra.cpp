#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
#include<math.h>
using namespace std;
class grafo{
 public:
    int para, peso;
};
class vertice{
 public:
    int id, distancia;
};
struct ordena{
    bool operator()(const vertice& vertice_1,const vertice& vertice_2) const{
        return vertice_1.distancia < vertice_2.distancia;
    }
};
vector<vector<grafo> >g_dijkstra(100);
int num_vertice, num_aresta;
int inf = pow(2,31);
int dijkrastra(int origem, int destino){
    vertice vert;
    vector<int>distancia;
    bitset<100>visitado;
    priority_queue<vertice,vector<vertice>,ordena>menor_caminho;
    for(int i = 0;i<num_vertice;i++){
        distancia.push_back(inf);
    }
    distancia[origem] = 0;
    vert.id = origem;
    vert.distancia = 0;
    menor_caminho.push(vert);
    while(!menor_caminho.empty()){
        vertice aux_vert = menor_caminho.top();
        int u = aux_vert.id;
        menor_caminho.pop();
        if(!visitado[u]){
            visitado.set(u);
            for(int i = 0;i<g_dijkstra[u].size();i++){
                if(distancia[g_dijkstra[u][i].para] > distancia[u] + g_dijkstra[u][i].peso){
                    distancia[g_dijkstra[u][i].para] = distancia[u] + g_dijkstra[u][i].peso;
                    aux_vert.id = g_dijkstra[u][i].para;
                    aux_vert.distancia = distancia[g_dijkstra[u][i].para];
                    menor_caminho.push(aux_vert);
                }
            }
        }
    }
    return distancia[destino];
}
int main(){
    int origem, destino;
    int de;
    cout << "Inserir numero de vertices e arestas: ";
    cin >> num_vertice >> num_aresta;
    cout << "Inserir origem e destino: ";
    cin >> origem >> destino;
    for(int i=0;i<num_aresta;i++){
        cout << "Inserir arestas: ";
        grafo aresta;
        cin >> de >> aresta.para >> aresta.peso;
        g_dijkstra[de].push_back(aresta);
    }
    cout << dijkrastra(origem, destino) << endl;
}
