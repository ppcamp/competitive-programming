#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define WORD 3 //tamanho do conjunto que origina uma palavra
typedef vector <bool> bitset;

int main(){
    bitset vet;
    string pd;
    int n, b = 0, i, aux; //sendo b o tamanho de vet antes da inser��o, ou seja (vet/2 - ap�s inserir)
    while(scanf("%i",&n) && n!=0){
        if(n < pd.size()*WORD) while(n){printf("%c",pd.at(n--));} //exibe s� at� o tamanho correspondido
        else{
            if(vet.empty()){ vet.push_back(0); }
            aux = vet.size();  //guarda a posi��o para que n�o entre em um loop
            i   = 0;
            while(b < (vet.size() - aux++)){ //insere os valores inversos
                vet.push_back(!vet[b++]);
                if(i == 2){//faz a convers�o dos bits e insere no final da string 'pd'
                    if      (!vet[i])  { pd.push_back('O');}
                    else if (!vet[i-1]){ pd.push_back('P');}
                    else               { pd.push_back('N');}
                    i = 0;
                }
                i++;
            }//if(i != vet.size()-1) //ainda restam valores
            cout << "pd" << endl;
        }
    }
}
/*  011 N
    010 0
    001 P
*/
