#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int nAlunos,aux, a=0,b=0;
    std::cin >> nAlunos;

    vector < vector < int > > matriz;
//    matriz[2][3]= 5

//    int **matriz = new int*[nAlunos];
    for(int i=0; i<nAlunos;i++){
        std::cin >> aux;
//        matriz[i] = new int[aux+1];
        matriz[i][0] = aux;
        for(int j=1; j<=aux; j++)
            std::cin >> matriz[i][j];
    }
    std::vector <int> gA, gB;
    gA.push_back(1);
    for(;a<gA.size(); a++){
        for(int k=1; k<=matriz[(gA[a])-1][0]; k++){
            aux = 1;
            for(int i=0; i<gB.size(); i++)
                if(matriz[(gA[a])-1][k] == gB[i])
                    aux = 0;
            if(aux == 1 || gB.empty())
                gB.push_back(matriz[(gA[a])-1][k]);
        }
        for(; b<gB.size(); b++){
            for(int k=1; k<=matriz[(gB[b])-1][0]; k++){
                aux = 1;
                for(int i=0; i<gA.size(); i++)
                    if(matriz[(gB[b])-1][k] == gA[i])
                        aux = 0;
                if(aux == 1)
                    gA.push_back(matriz[(gB[b])-1][k]);
            }
        }
    }
    sort(gA.begin(),gA.end());
    std::cout << gA[0];
    for(int i=1; i<gA.size(); i++)
        std::cout << " " << gA[i];

    sort(gB.begin(),gB.end());
    std::cout << "\n" << gB[0];
    for(int i=1; i<gB.size(); i++)
        std::cout << " " << gB[i];
}
    //Para exibir a matriz
    /*for(int i=0; i<nAlunos; i++){
        for(int j=1; j<=matriz[i][0]; j++)
            std::cout << matriz[i][j] << "\t";
        std::cout << std::endl;
    }

	///Casos teste
	13
	2 12 9
	1 10
	3 8 12 13
	5 8 10 13 6 5
	2 11 4
	1 4
	1 8
	3 4 3 7
	1 1
	2 2 4
	1 5
	2 3 1
	2 4 3


	15
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	1 13
	14 11 7 1 10 8 6 14 12 3 2 15 5 4 9
	1 13
	1 13

	*/
