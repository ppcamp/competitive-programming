#include <iostream>
#include <queue>
#include <vector>

int main(){
    int n, i=1;
    std::queue <int> fila;
    std::vector <int> discarded;
    while(std::cin >> n && n>0){
        i=1;
        while(i <= n)
            fila.push(i++);
        while(fila.size()>1){
            discarded.push_back(fila.front());
            fila.pop();
            fila.push(fila.front());
            fila.pop();
        }
        std::cout << "Discarded cards: 1";
        for(n = 1; n<discarded.size(); n++)
            std::cout << ", " << discarded[n];
        std::cout << "\nRemaining card: " << fila.front() << std::endl;
        while(!fila.empty())
            fila.pop();
        discarded.clear();
    }
}
