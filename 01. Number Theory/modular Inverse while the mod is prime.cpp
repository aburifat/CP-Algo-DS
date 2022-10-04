#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power, ll mod){
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

ll modInv(ll a, ll mod){
    return binpow(a,mod-2,mod);
}
