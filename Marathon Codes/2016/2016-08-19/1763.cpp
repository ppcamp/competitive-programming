#include <iostream>
#include <ctype.h>
#include <map>

int main(){
    std::map <std::string,std::string> tabela;
    tabela["brasil"]          = "Feliz Natal!";
    tabela["alemanha"]        = "Frohliche Weihnachten!";
    tabela["austria"]         = "Frohe Weihnacht!";
    tabela["coreia"]          = "Chuk Sung Tan!";
    tabela["espanha"]         = "Feliz Navidad!";
    tabela["grecia"]          = "Kala Christougena!";
    tabela["estados-unidos"]  = "Merry Christmas!";
    tabela["inglaterra"]      = "Merry Christmas!";
    tabela["australia"]       = "Merry Christmas!";
    tabela["portugal"]        = "Feliz Natal!";
    tabela["suecia"]          = "God Jul!";
    tabela["turquia"]         = "Mutlu Noeller";
    tabela["argentina"]       = "Feliz Navidad!";
    tabela["chile"]           = "Feliz Navidad!";
    tabela["mexico"]          = "Feliz Navidad!";
    tabela["antardida"]       = "Merry Christmas!";
    tabela["canada"]          = "Merry Christmas!";
    tabela["irlanda"]         = "Nollaig Shona Dhuit!";
    tabela["belgica"]         = "Zalig Kerstfeest!";
    tabela["italia"]          = "Buon Natale!";
    tabela["libia"]           = "Buon Natale!";
    tabela["siria"]           = "Milad Mubarak!";
    tabela["marrocos"]        = "Milad Mubarak!";
    tabela["japao"]           = "Merii Kurisumasu!";

    std::string linha;
    while(getline(std::cin,linha)){
        for(int i=0; i<linha.length(); i++)
            linha.at(i) = tolower(linha.at(i));
        if(tabela.find(linha) != tabela.end())
            std::cout << tabela.find(linha)->second << std::endl;
        else{
            std::cout << "--- NOT FOUND ---" << std::endl;
        }
    }
    return 0;
}
