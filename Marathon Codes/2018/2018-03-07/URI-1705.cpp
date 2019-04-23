// Problem URI:1705

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define TAM 100//10000000
ll _sieve_size;
string s;
bool aux;

bitset<TAM> bs;
vector<int> primes;
vector<int> slc;

void sieve(long long upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    slc.push_back(1);
    for(ll i=2; i<= _sieve_size; i++){
        if(bs[i])
            for(ll j=i*i; j<= _sieve_size; j+=i)
                bs[j]=0;
        else{
            s.clear();
            s = to_string(i);
            aux = true;
            printf("TAMANHO DA STRING: %i: ", (int)s.size());
            //for(auto i: s) printf("%c", i);

            for(ll j=0; j<s.size(); j++){
                if(s[j]!='0' && s[j]!='1')
                    printf("%c ", s[j]);
                else
                    printf(" MERDA");
            }
            printf("\n");
            if(aux)
                slc.push_back((int)i);

        }
    }
}
int main(){
    sieve(TAM);
    ofstream os("nPrimos.txt", ofstream::out);
    for(auto i:slc) os << i << ",";
    os.close();

}
