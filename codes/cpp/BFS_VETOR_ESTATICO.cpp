#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector <pii> vii;
typedef vector<bool> bitset;


int matriz[1000][1000];

/*
 *	Posição 0 - Op 1
 *	Posição 1 - Op 2
 *	 [...]    - Op ...
 */
void geraLig(int lig){
	matriz[lig][0] = lig*2;
	matriz[lig][1] = lig*3;
	matriz[lig][2] = lig/2;
	matriz[lig][3] = lig/3;
	matriz[lig][4] = lig+7;
	matriz[lig][5] = lig-7;	
}

int bfs(int N, int M){
	queue <int> fila;
	fila.push(N);
	
	while(!fila.empty()){
		for(int j=0; j<6; j++){
			
		}
	}
}

int main() {
	int N, M;
	scanf("%i %i", &N, &M);
	
	
	
	return EXIT_SUCCESS;
}
