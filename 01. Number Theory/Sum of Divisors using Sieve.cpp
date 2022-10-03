#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pub push_back
#define vl vector<ll>

const ll MX=1000010;

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


ll sumDiv(ll n)
{
    ll ans=1;
    for(ll i=0;primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ll power=1;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                power++;
            }
            ans*=(powl(primes[i],power)-1)/(primes[i]-1);
        }
    }
    return ans;
}


int main()
{
    sieve(100000);
    cout<<sumDiv(12)<<endl;
    return 0;
}

