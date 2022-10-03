#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0){
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
    ll x,y;
    ll g=exGCD(a,mod,x,y);
    if(g!=1)return -1; //No Solution
    x=(x%mod+mod)%mod;
    return x;
}


/// a * x = b (mod m)
bool linConEqn(ll a, ll b, ll m, ll &g, ll &mp, ll &x)
{
    g=gcd(a,m);
    if(g!=1){
        if(b%g)return false; // No Solution
        a/=g; /// (a/g) * x = (b/g) (mod (m/g))
        b/=g; /// a' * x = b' (mod m')
        m/=g;
    }
    ll ai=modInv(a,m);
    x=bigMul(b,ai,m);
    mp=m; /// mp is m'
    return true;
}

int main()
{
    ll a=2,b=4,m=3;
    ll g, mp, x;
    bool ck=linConEqn(a,b,m,g,mp,x);
    if(ck){
        for(ll i=0;i<g;i++){
            cout<<(x+(i*mp))<<endl;
        }
    }else{
        cout<<"No Solution"<<endl;
    }
}
