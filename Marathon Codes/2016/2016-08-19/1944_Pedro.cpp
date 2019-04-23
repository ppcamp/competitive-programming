#include <iostream>
#include <stack>
int main(){
    int n,cont=0;
    char c;//auxiliar de entrada
    bool aux;
    std::string linha;
    std::stack <std::string> pilha;
    std::cin >> n;
    while(n>0){
        aux = true;
        if(pilha.empty())
            pilha.push("FACE");
        for(int i=0; i<4; i++){//usando o getline ou gets ele nao da accepted
           std::cin >> c;
           linha.push_back(c);
        }
        for(int i=3,j=0; i>=0 && aux==true; i--,j++)
            if(linha.at(i) != (pilha.top()).at(j))
                aux = false;
        if(aux){
            pilha.pop();
            cont++;
        }
        else
            pilha.push(linha);
        linha.clear();
        n--;
    }
    std::cout << cont << std::endl;
}
