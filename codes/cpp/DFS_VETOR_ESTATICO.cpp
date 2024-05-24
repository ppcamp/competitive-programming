#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector <pii> vii;
typedef vector<bool> bitset;

bool visitados[49];
bool adjacencia[49][49];

int s = 0;
int indent = 0, p = 0;

void dfs (int n) {
	visitados[n] = true;

	for (int i = 0; i < 7; i++) {
		p = 0;
		printf ("S = %i\t", s);

		while (p < indent) {
			printf ("\t");
			p++;
		}

		printf ("ADJACENCIA[%i][%i] = %i\n", n, i, adjacencia[n][i]);

		if (!adjacencia[n][i] || visitados[i]) { continue; }    //if (adjacencia[n][i] && !visitados[i]) {

		s++;
		indent++;
		dfs (i);
		indent--;
		s++;
	}


}

int main() {
	adjacencia[0][2] = adjacencia[2][0] = 1;
	adjacencia[0][5] = adjacencia[5][0] = 1;
	adjacencia[0][4] = adjacencia[4][0] = 1;
	adjacencia[3][5] = adjacencia[5][3] = 1;
	dfs (1);
	cout << s << endl;
	return EXIT_SUCCESS;
}
