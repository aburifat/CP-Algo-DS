#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod=998244353;

ll binpow(ll base, ll power)
{
    base%=mod;
    power%=(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll modInv(ll a)
{
    return binpow(a,mod-2,mod);
}
