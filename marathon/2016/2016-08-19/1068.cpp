#include <iostream>

bool verifica(std::string linha){
    int a=0,b=0;
    for(int i=0; i<linha.size(); i++){
        if(b>a)
            return false;
        else if(linha.at(i) == '(')
            a+=1;
        else if(linha.at(i) == ')')
            b+=1;
    }
    return (a == b)? true : false;
}

int main(){
    std::string linha;
    while(std::cin >> linha){
        (verifica(linha))? std::cout << "correct" << std::endl : std::cout << "incorrect" << std::endl;
    }
    return 0;
}
