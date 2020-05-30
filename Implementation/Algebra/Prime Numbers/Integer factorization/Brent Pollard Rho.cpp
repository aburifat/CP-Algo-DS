#include<bits/stdc++.h>
using namespace std;

ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}


ll f(ll x, ll c, ll mod) {
    return (bigMul(x, x, mod) + c) % mod;
}

ll brent(ll n, ll x0=2, ll c=1) {
    ll x=x0;
    ll g=1;
    ll q=1;
    ll xs, y;

    ll m=128;
    ll l=1;
    while(g==1) {
        y=x;
        for(ll i=1;i<l;i++)x=f(x,c,n);
        ll k=0;
        while(k<l&&g==1) {
            xs=x;
            for(ll i=0;i<m&&i<l-k;i++) {
                x=f(x,c,n);
                q=bigMul(q,abs(y-x),n);
            }
            g=__gcd(q,n);
            k+=m;
        }
        l*=2;
    }
    if(g==n){
        do{
            xs=f(xs,c,n);
            g=__gcd(abs(xs-y),n);
        }while(g==1);
    }
    return g;
}

int main()
{
    ll n;
    cin>>n;
    set<ll>fact;
    unordered_map<ll,ll>factCt;
    while(n>1){
        ll tmp=brent(n);
        factCt[tmp]++;
        fact.insert(tmp);
        n/=tmp;
    }
    bool t=false;
    for(auto u:fact){
        if(t)cout<<" ";
        else t=true;
        cout<<u<<"^"<<factCt[u];
    }
    cout<<"\n";
}


