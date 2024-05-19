// Problem: UVA 10140

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define TAM 1e7         // For big numbers needs up to 4 sec and memo does overflow

ll _sieve_size_ = 0;       // Var used to manual verification in the prime list
bitset<(int)TAM> vb;
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

bool isPrime(ll n){
    if(n < _sieve_size_) return vb[n];
    for(auto i: primes) if(n%i == 0) return false;  // Verifies with the prime list created
    return true;
}

int main(){
    int l, u, dist, v[2], aux, cont;
    bool t1,t2;
    sieve(TAM);     // Create the list of prime number in 1e7 order

    while(cin >> l >> u){
        for(aux=cont=dist=t1=t2=0; l<=u; l++){
            if(isPrime(l)){
                if(cont == 0)   // Always save last prime number, unless your count is significant
                    aux = l;
                if(isPrime(l+1) && !t1){
                    printf("%i,%i are closest, ", l, l+1);
                    t1=1;       // Catch the first adjacent prime numbers in sequence
                }
                if(cont >= dist){
                    if(cont > dist){
                        v[0] = aux;
                        v[1] = l;
                        dist = cont;
                    }
                    aux = l;
                    t2 = 1;     // There are at least 2 prime numbers in range
                }
                cont=0;
            }
            else if(aux != 0)
                cont++;
        }
        (!t2)? printf(" %i, %i are the most distant.\n", v[0], v[1]) : printf("Didn't have 2 prime numbers in interval\n");
    }
    return 0;
}
