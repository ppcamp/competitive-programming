#include <iostream>
#include <map>
using namespace std;

int main(){
    map <string,string> assinaturas;
    int n,cont;
    string aux1,aux2;
    while(cin >> n && n!=0){
        assinaturas.clear();
        cont = 0;
        while(n>0){
            cin >> aux1 >> aux2;
            assinaturas[aux1] = aux2;
            n--;
        }
        cin >> n;
        while(n>0){
            cin >> aux1 >> aux2;
            for(int i=0,j=0; i<aux2.size() && j<=1; i++){
                if(assinaturas.find(aux1)->second.at(i) != aux2.at(i))
                    j++;
                if(j>1)
                    cont++;
            }
            n--;
        }
        cout << cont << endl;
    }
    return 0;
}
