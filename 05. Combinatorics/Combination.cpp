#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX=500009;
constexpr ll mod=998244353;
vector<ll>fact;

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

ll modInv(ll a)
{
    ll x, y;
    ll g=exGCD(a,mod,x,y);
    if(g!=1){
        return -1;
    }
    else{
        x=(x%mod+mod)%mod;
        return x;
    }
}

ll bigMul(ll a, ll b)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}


void preCom()
{
    fact.resize(MX+1);
    fact[0]=1;
    for(ll i=1;i<=MX;i++){
        fact[i]=bigMul(fact[i-1],i);
    }
}

ll Combination(ll n, ll k)
{
    if(n<k)return 0;
    return fact[n]*modInv(fact[k])%mod*modInv(fact[n-k])%mod;
}

int main()
{
    preCom();
    ll n=3,k=4;
    ll ans=Combination(n,k);
    cout<<ans<<endl;
    return 0;
}
