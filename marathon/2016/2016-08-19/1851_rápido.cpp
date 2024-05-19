#include <iostream>
#include <queue>
using namespace std;
class dragoes{ //com struct de 0,192 vai para ~0,400 e usando funcoes para obter os valores privados, vai para 0,338
	public:
		unsigned long long int chegada, nec, multa;
		dragoes(unsigned long long int c, unsigned long long int n, unsigned long long int m){
			chegada = c;
			nec 	= n;
			multa	= m;
		}
};
int main(){
	unsigned long long int dia = 1, multa, nec, reset, soma = 0;
	priority_queue <pair <float, dragoes*> > fila;
	cin >> reset >> multa;
	while( cin >> nec >> multa){
		dragoes *ptr	=	new dragoes(++dia, nec, multa);
		fila.push(make_pair((multa/(nec*1.0)), ptr));
		if(dia == (reset+1)){
			soma	+= (dia - fila.top().second->chegada) * fila.top().second->multa;
			reset	+= fila.top().second->nec; //Dias necessarios para terminar um dragao
			fila.pop();	//remove o primeiro
		}
	}
	while(!fila.empty()){
		if(++dia == (reset+1)){
			soma	+= (dia - fila.top().second->chegada) * fila.top().second->multa;
			reset	+= fila.top().second->nec; //Dias necessarios para terminar um dragao
			fila.pop();	//remove o primeiro
		}
	}
	cout << soma << endl;
}
