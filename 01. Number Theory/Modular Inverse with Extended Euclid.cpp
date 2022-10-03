#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll modInv(ll a, ll mod)
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

int main()
{
    ll a=2,m=1000000007;
    ll ans=modInv(a,m);
    if(ans==-1)cout<<"No Solution!\n";
    else cout<<ans<<"\n";
    return 0;
}
