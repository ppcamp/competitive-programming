#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(){
	int testes, tamDicionario, tamTestes;
	size_t flag;
	cin >> testes;

	map <string, string> dicionario;
	stringstream ss;
	string palavra, significado;

	while(testes > 0){
		cin >> tamDicionario >> tamTestes;
		while(tamDicionario > 0){
			//ss.clear();
			//significado.clear();
			//palavra.clear();
			getline(cin >> ws, palavra);
			getline(cin >> ws, significado);
			dicionario.insert(make_pair(palavra, significado));
			tamDicionario--;
		}
		while(tamTestes > 0){
			ss.clear();
			//significado.clear();
			//palavra.clear();
			getline(cin >> ws, palavra);
            flag = palavra.size();
            ss << palavra;
			while(ss >> significado){
                --flag -= significado.size();   //cada vez que sai do ss tira um '\n' e tira o tamanho das palavras
				if(dicionario.find(significado) != dicionario.end())
					cout << dicionario.find(significado)->second;
				else
					cout << significado;
				if((int)flag > 0) cout << " ";
			}
			cout << endl;
			tamTestes--;
		}
		dicionario.clear();
		cout << endl;
		testes--;
	}
	return 0;
}
