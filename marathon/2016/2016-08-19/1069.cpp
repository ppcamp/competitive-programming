#include <iostream>
#include <stack>

int main(){
    std::stack <bool> pilha;
    int n,cont;
    std::string aux;
    std::cin >> n;
    while(n>0){
        cont=0;
        std::cin >> aux;
        for(int i=0; i<aux.length(); i++){
            if(aux.at(i) == '<')
                pilha.push(1);
            else if(aux.at(i) == '>'){
                if(!pilha.empty()){
                    pilha.pop();
                    cont++;
                }
            }
        }
        while(!pilha.empty())
            pilha.pop();
        std::cout << cont << std::endl;
        n--;
    }
}
