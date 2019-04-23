#include <iostream>
#include <map>

int main(){
    std::map <std::string,bool> convidados;
    std::map <std::string,bool> ::iterator it;
    std::string linha, verifica, aux = "s";
    while(std::cin >> linha && linha!="FIM"){
        std::cin >> verifica;
        if(convidados.count(linha) == 0){
            if(verifica == "YES"){
                convidados.insert(std::make_pair(linha,true));
                if(linha.size() > aux.size())
                    aux = linha;
            }
            else if(verifica == "NO")
                convidados.insert(std::make_pair(linha,false));
        }
    }
    for(it=convidados.begin(); it!=convidados.end(); it++)
        if(it->second == true)
            std::cout << it->first << std::endl;
    for(it=convidados.begin(); it!=convidados.end(); it++)
        if(it->second == false)
            std::cout << it->first << std::endl;
    convidados.clear();
    std::cout << "\nAmigo do Habay:\n" << aux << std::endl;
    return 0;
}
