#include <iostream>

#define C_e_F 137
#define B_e_S 149

int main(){
    std::string linha, pilha;
    size_t tam;
    while(std::getline(std::cin, linha)){
        tam = 0;
        for(int i=0; i<linha.size(); i++){
            pilha.push_back(linha.at(i));
            if(!pilha.empty() && ((*(pilha.end()-1) + *(pilha.end()-2) == C_e_F) || (*(pilha.end()-1) + *(pilha.end()-2) == B_e_S))){
                pilha.pop_back();
                pilha.pop_back();
                tam++;
            }
        }
        pilha.clear();
        std::cout << tam << std::endl;
    }
}
