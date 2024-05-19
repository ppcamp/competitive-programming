#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
int main ()
{
	map<string,string> dicionario;
	int T, M, N;
	string origem, traducao;
	cin >> T;
	stringstream ss;
	for(int c=0;c<T;++c) {
		cin >> M >> N;
		cin.ignore();
		for(int l=0;l<M;++l) {
			getline(cin, origem);
			getline(cin, traducao);
			dicionario[origem]=traducao;
		}
		for(int l=0;l<N;++l) {
			getline(cin, origem);
			ss << origem; // passa a linha inteira pra ss
//reutilizando origem porque não precisaremos mais dela, já que foi copiada pro ss.
			ss >> origem; // passa a primeira palavra
						  // ainda não usada para origem.
            try {
				cout << dicionario.at(origem);
			} catch(...) {
				cout << origem;
			}
			while(ss>>origem) {
				try {
					cout << ' ' << dicionario.at(origem);
				} catch(...) {
					cout << ' ' << origem;
				}
			}
			ss.clear();
			cout << endl;
		}
		dicionario.clear();
		cout << endl;
	}
	return 0;
}
