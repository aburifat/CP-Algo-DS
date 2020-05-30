#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX = 1e8;
ll minPF[MX+1];
vector<ll>primes;

void sieve(ll ub) {
    for (ll i=2; i<=ub; ++i) {
        if (minPF[i] == 0) {
            minPF[i] = i;
            primes.push_back(i);
        }
        for (ll j=0; j<(ll)primes.size() && primes[j]<=minPF[i] && i*primes[j]<=ub; ++j)
            minPF[i * primes[j]] = primes[j];
    }

}

int main()
{
    sieve(MX);
    for(ll i=0;i<100;i++){
        cout<<primes[i]<<"\n";
    }
    return 0;
}
