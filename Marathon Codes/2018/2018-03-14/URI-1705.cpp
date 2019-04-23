#include <cstdio>
#include <bitset>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lf;
/*
bitset<2500> mark;
ll _sieve_size;
stringstream ss;

void sieve(ll s){
	int _sieve_size=s+1;
	mark.set(); mark.set(0,0); mark.set(1,0);
	for(ll i=0; i<=_sieve_size; i++){
		if(mark[i]){
			for(ll j=i*i; j<=_sieve_size; j+=i) mark[j]=0;
			primes.push_back((int) i);
		}
	}
}

bool isPrime(ll n){
	if(n<=_sieve_size) return mark[n];
	ll i = 0, stop = int(sqrt(n) + 0.05);
	while(i<primes.size()){
		if(n%primes[i]) return false; i++
	}
	for(i=*(primes.end()-1); i<= stop; i++)
		if(n%i==0) return false;
	return true;
}
bool lookBinary(ll i){
	ss << i;
	string value;
	ss >> value;
	if(find_first_not_of("1")!=-1 && find_first_not_of("0")!=-1); 
	

*/	
int main(){
	ll n;
	while(scanf("%i", &n)){
			
	}		
	return 0;
}
