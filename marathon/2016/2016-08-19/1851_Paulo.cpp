#include<bits/stdc++.h>
using namespace std;
//Class usado como se fosse struct, nao sei pra que serve mas e necessario ser class para fazer a sobrecarga na fila.

class dragao{
    public:
        unsigned long long dia, multa;
        double media_multa;
};
// Sobrecarga para a minha fila, a forma em que vou ordenar, compara novo topo com antigo topo.

struct sobrecarga{
    bool operator()(const dragao &new_drag,const dragao &old_drag) const{
        return new_drag.media_multa < old_drag.media_multa;
    }
};

int main(){
    unsigned long long multa_dia=0,multa_total=0;
    unsigned long long tempo = 0;
    // fila<nome da classe,o que eu vou colocar na fila, nome da sobrecarga com a forma de ordenacao.
    priority_queue <dragao,vector<dragao>,sobrecarga>treino;
    dragao new_dragao;

    while(cin >> new_dragao.dia >> new_dragao.multa){

        new_dragao.media_multa = (1.0*new_dragao.multa)/new_dragao.dia;
        multa_dia += new_dragao.multa;
        treino.push(new_dragao);

        if(tempo == 0){
            tempo = treino.top().dia;
            multa_dia -= treino.top().multa;
            treino.pop();
        }

        --tempo;
        multa_total += multa_dia;
    }
    while(!treino.empty()){
        if(tempo == 0){
            tempo = treino.top().dia;
            multa_dia -= treino.top().multa;
            treino.pop();
        }

        --tempo;
        multa_total += multa_dia;
    }
    cout << multa_total << endl;
    return 0;
}
