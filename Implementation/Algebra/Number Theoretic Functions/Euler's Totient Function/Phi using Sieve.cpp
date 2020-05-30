#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;

bitset<10000010>bs;
ll ss;
vector<ll> primes;

void sieve(ll ub) {
    ss=ub+1;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ss;i+=2){
        bs[i]=0;
    }
    for(ll i=3; i<=ss; i+=2) {
        if(bs[i]) {
            for(ll j=i*i; j<=ss; j+=i) {
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
}

ll phi(ll n) {
    ll PF_idx=0, PF=primes[PF_idx], ans=n;
    while(PF*PF<=n) {
        if(n%PF==0)
            ans-=(ans/PF);
        while(n%PF==0)
            n/=PF;
        PF=primes[++PF_idx];
    }
    if(n!=1)
        ans-=(ans/n);
    return ans;
}


int main()
{
    sieve(MX);
    cout<<phi(10)<<endl;
    return 0;
}
