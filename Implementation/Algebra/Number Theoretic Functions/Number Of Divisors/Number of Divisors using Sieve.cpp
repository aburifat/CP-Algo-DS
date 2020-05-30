#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pub push_back
#define vl vector<ll>

const ll MX=100010;

bitset<10000010>bs;
ll ss;
vl primes;

void sieve(ll ub) {
    ss=ub+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=ss; i++) {
        if(bs[i]) {
            for(ll j=i*i; j<=ss; j+=i) {
                bs[j]=0;
            }
            primes.pub(i);
        }
    }
}

ll numDiv(ll n) {
    ll PF_idx=0, PF=primes[PF_idx], ans=1;
    while(PF*PF<=n) {
        ll power=0;
        while(n%PF==0) {
            n/=PF;
            power++;
        }
        ans*=(power+1);
        PF=primes[++PF_idx];
    }
    if(n>1)
        ans*=2;
    return ans;
}

int main() {
    sieve(MX);
    cout<<numDiv(10)<<endl;
    return 0;
}
