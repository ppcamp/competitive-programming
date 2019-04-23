#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class grafo{
 public:
    int de, para, peso;
};
struct ordena{
    bool operator()(const grafo& aresta_1,const grafo& aresta_2) const{
        return aresta_1.peso < aresta_2.peso;
    }
};
vector<grafo>kruskal;
vector<int>disjoint_set;
int soma_total=0;
int findset(int vert){
    if(disjoint_set[vert] != vert)
        disjoint_set[vert] = findset(disjoint_set[vert]);
    return disjoint_set[vert];
}
void k_union(int de, int para, int i){
    int grupo_1, grupo_2;
    grupo_1 = findset(de);
    grupo_2 = findset(para);
    if(grupo_1 != grupo_2){
        soma_total += kruskal[i].peso;
        if(grupo_1 > grupo_2)
            disjoint_set[grupo_1] = grupo_2;
        else
            disjoint_set[grupo_2] = grupo_1;
    }
}
int main(){
    int num_vertice, num_aresta;
    cout << "Insira numero de vertices e arestas: ";
    cin >> num_vertice >> num_aresta;
        for(int i=0;i<num_aresta;i++){
            cout << "Insira a aresta(de, para, peso): ";
            grafo aresta;
            cin >> aresta.de >> aresta.para >> aresta.peso;
            kruskal.push_back(aresta);
        }
        sort(kruskal.begin(),kruskal.end(),ordena());
        for(int i = 0;i<num_vertice;i++){
            disjoint_set.push_back(i);//makeset
        }
        for(int i = 0;i<kruskal.size();i++){
            k_union(kruskal[i].de, kruskal[i].para, i);
        }
        cout << "A min spanning tree e: " <<  soma_total << endl;
        soma_total = 0;
        kruskal.clear();
        disjoint_set.clear();
}
