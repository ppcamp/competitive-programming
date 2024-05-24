#include <bits/stdc++.h>
using namespace std;
long long _sieve_size;
bitset<10000000> bs;
vector<int> primes;

void sieve(long long upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i=2; i<= _sieve_size; i++)
        if(bs[i]){
            for(long long j=i*i; j<= _sieve_size; j+=i)
                bs[j]=0;
        primes.push_back((int)i);
        }
}
/*
bool isPrime(long long N){
    if(N <= _sieve_size) return bs[N];
    for(int i=0; i< (int) primes.size(); i++)
        if(N% primes[i] == 0) return false;
    return true;
}*/

int main(){
    sieve(103);
    /*printf("%d\n", isPrime(2147483647));
    printf("%d\n", isPrime(214783647));
    printf("%d\n", isPrime(15));
    printf("%d\n", isPrime(21));
    printf("%d\n", isPrime(23));
    printf("%d\n", isPrime(111));

    ofstream os("primos.txt", ofstream::out | ofstream::app);
    for(auto i:primes) os << i <<",";
    os.close();
    */

    for(auto i: primes) printf("%i,", i);
    return 0;
}
