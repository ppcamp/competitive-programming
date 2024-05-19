// URI: 2180
#include <bits/stdc++.h>
#include <bitset>
using namespace std;		// 2^(4*8) - 1 max int value

#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;

bitset<100000> mark;
     //60000
vi primes;

void sieve(ll s){
	s+=1;
	mark.set(); mark.set(0,0); mark.set(1,0);
	for(ll i=0; i<=s; i++){
		if(mark[i]){
			for(ll j=i*i; j<=s; j+=i)
				mark.set(j,0);
			primes.pb((int) i);
		}
	}
}
bool isPrime(ll pos){
	if(pos <= 60000) return mark[pos];
	for(int i=0; i<sqrt(primes.size()); i++)
		if(pos%primes[i] == 0) return false;
	return true;
}

int main(){
	sieve(60000);
	int weight, i=10, sum=0;
	scanf("%i", &weight);
	while(i){
		while(!isPrime(weight)) weight++;
		sum+=weight++;
		i--;
	}
	printf("%i km/h\n", sum);
	sum=60e6/sum;
	printf("%i h / %i d\n", sum, sum/24);
	return 0;
}
