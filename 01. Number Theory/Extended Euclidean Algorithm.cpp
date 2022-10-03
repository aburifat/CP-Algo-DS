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

int main()
{
    ll a, b;
    a=12,b=3;
    ll x,y;
    ll ans=exGCD(a,b,x,y);
    cout<<x<<"*"<<a<<" + "<<y<<"*"<<b<<" = "<<ans<<endl;
    return 0;
}
