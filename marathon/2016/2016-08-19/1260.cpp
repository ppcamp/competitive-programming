#include <iostream>
#include <map>

using namespace std;

int main(){
    string linha;
    map <string, double> especies;
    int n, cont;
    cout.precision(4);
    cin >> n;
    cin >> ws; //pega linha em branco e ja faz a limpeza do buffer
    while(n >= 0){
        cont = 0;
        while(getline(cin,linha) && !linha.empty()){
            cont++;
            if(especies.find(linha) != especies.end())
                especies[linha]++;
            else
                especies.insert(make_pair(linha, 1));
        }
        while(!especies.empty()){
            cout << std::fixed << especies.begin()->first << " " << (especies.begin()->second*100.0)/cont << endl;
            especies.erase(especies.begin());
        }
        if(n > 1) cout << endl;
        n--;
    }
    return 0;
}
