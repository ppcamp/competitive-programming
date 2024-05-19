// URI: 1694
#include <cstdio>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;

bitset<2500> mark;
int matrix[50][50];

void sieve(ll s){
	int _sieve_size=s+1;
	mark.set(); mark.set(0,0); mark.set(1,0);
	for(ll i=0; i<=_sieve_size; i++){
		if(mark[i])
			for(ll j=i*i; j<=_sieve_size; j+=i) mark[j]=0;//primes.push_back((int) i);
	}
}
ld nF(ll n){
	return (n==0)? 1 : n*nF(n-1);
}
ld nCr(ll n, ll r){			//nCr = n!/r!(n-r)!
	if(r>n) return 0;		//Error, returns 0;
	if(r==1) return n;
	if(n==r) return 1;
	
	ld result=1;
	ll div,f;
	if(r>n-r){
		f=r;
		div=n-r;
	}
	else{
		f=n-r;
		div=r;
	}
	for(ll i=n; i>f; i--)
		result*=i;
	return (result/nF(div));
}
ll createMatrix(int row,int col, int k=1){
	ll aux=0;
	for(int i=0,cont=0, colC=0; i<row; i++, colC=0){
		for(int j=0; j<col; j++,cont++){
			if(!mark[cont]){
				matrix[i][j] = (int)cont;
				colC++;
			}
			else matrix[i][j]=-1;
		}
		aux+=nCr(colC,k);
	}
	return aux;
}
int main(){
	int m,n,k;
	ld aux;
	sieve(2500);
	
	while(scanf("%i %i %i", &m,&n,&k) && m!=0 && n!=0 && k!=0){
		aux = createMatrix(m,n, k);	//create matrix and verifies with column
		if(k!=1){	// do not count same number twice in case k=1
			for(int j=0,rowC=0; j<n; j++, rowC=0){	//verifies with row
				for(int i=0; i<m; i++)
					if(matrix[i][j]!=-1) rowC++;
				aux+=nCr(rowC,k);
			}
		} 
		printf("%.0LF\n", aux);
	}
	return 0;
}
