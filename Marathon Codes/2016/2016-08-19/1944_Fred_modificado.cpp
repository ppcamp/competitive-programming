#include <iostream>
int main(){
    std::string face;
    char letra;
    bool igual = true;
    int n,cont=0;
    std::cin >> n;
    for(int i=0,aux=8; i<n; i++, aux=8,igual=true){
        if(face.empty())
            face = "FACE";
        for(int j=0;j<4;j++){
            std::cin >> letra;
            face.push_back(letra);
        }
        for(int j=face.size()-1;j>face.size()-5 && igual == true; j--, aux--)
            if(face[j]!=face[face.size()-aux])
                igual = false;
        if(igual){
            cont++;
            for(int j=0;j<8;j++)
                face.erase(face.end()-1);
        }
    }
    std::cout << cont << std::endl;
}
