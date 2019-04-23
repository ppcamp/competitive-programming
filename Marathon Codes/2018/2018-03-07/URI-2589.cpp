// Problem: URI 2589

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const ll TAM = 1e9;         // For big numbers needs up to 4 sec and memo does overflow

ll _sieve_size_ = 0;       // Var used to manual verification in the prime list
bitset<TAM> vb;
vector<int> primes;

#define ti(i) printf("%i\n", i);    // Tests
#define tc(c) printf("%c\n", c);

void sieve(ll _size_){
    _sieve_size_ = _size_ +1;
    vb.set();
    vb.set(0,0); vb.set(1,0);   // 0 & 1 are not prime numbers
    _sieve_size_ += 2;             // to catch the until the last number in bitset
    for(ll i=2; i<_sieve_size_; i++)
        if(vb[i]){
            for(ll j=i*i; j<=_sieve_size_; j+=i)
                vb[j]=0;
            primes.push_back(i);
        }
}

int main(){
    int N,dist,dif;
    sieve(TAM);     // Create the list of prime number in 1e7 order
    while(cin >> N){
        dif=dist=0;
        for(int i=0; primes[i+1] < N; i++){
            dif = primes[i+1] - primes[i];//ti(primes[i+1]);
            if(dif > dist)
                dist = dif;
        }
        printf("Distancia: %i\n", dist);
    }
    return 0;
}
