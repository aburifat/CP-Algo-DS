#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr long long MX=1e5;

bitset<100010>bs;
vector<ll> primes;

void sieve(ll ub) {
    ub++;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3; i<=ub; i+=2) {
        if(bs[i]) {
            for(ll j=i*i; j<=ub; j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}

unordered_map<ll,ll>PHI;
ll phi(ll n) {
    if(PHI[n])return PHI[n];
    ll PF_idx=0, PF=primes[PF_idx], ans=n, num=n;
    while(PF*PF<=n) {
        if(n%PF==0)
            ans-=(ans/PF);
        while(n%PF==0)
            n/=PF;
        PF=primes[++PF_idx];
    }
    if(n!=1)
        ans-=(ans/n);
    return PHI[num]=ans;
}

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    if(bs[mod])power=power%(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll modInv(ll a, ll m)
{
    if(__gcd(a,m)!=1)return -1;
    if(bs[m]) return binpow(a,m-2,m);
    else return binpow(a,(phi(m)-1),m);
}

int main()
{
    sieve(MX);
    ll a=21,m=43;
    ll ans=modInv(a,m);
    if(ans==-1)cout<<"No Solution!"<<endl;
    else{
        cout<<ans<<endl;
    }
    return 0;
}

