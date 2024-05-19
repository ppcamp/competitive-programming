#include <iostream>
#include <queue>
using namespace std;
class dragoes{
	private:
		unsigned long long int chegada, nec, multa;
	public:
		dragoes(unsigned long long int c, unsigned long long int n, unsigned long long int m){
			chegada = c;
			nec 	= n;
			multa	= m;
		}
		unsigned long long int get_nec(){ return nec; }
		unsigned long long int get_chegada(){ return chegada; }
		unsigned long long int get_multa(){ return multa; }
};
int main(){
	unsigned long long int dia = 1, multa, nec, reset;
	unsigned long long int soma = 0;
	priority_queue <pair <float, dragoes*> > fila;
	cin >> reset >> multa;
	while( cin >> nec >> multa){
		++dia;
		dragoes *ptr	=	new dragoes(dia, nec, multa);
		fila.push(make_pair((multa/(nec*1.0)), ptr));

		if(dia == (reset+1)){
			soma	+= (dia - fila.top().second->get_chegada()) * fila.top().second->get_multa();
			reset	+= fila.top().second->get_nec(); //Dias necessarios para terminar um dragao
			fila.pop();	//remove o primeiro
		}
	}
	while(!fila.empty()){
		++dia;
		if(dia == (reset+1)){
			soma	+= (dia - fila.top().second->get_chegada()) * fila.top().second->get_multa();
			reset	+= fila.top().second->get_nec(); //Dias necessarios para terminar um dragao
			fila.pop();	//remove o primeiro
		}
	}
	cout << soma << endl;
}
