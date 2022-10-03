#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0){
        x=1; y=0; return a;
    }
    ll x1,y1;
    ll d=exGCD(b,a%b,x1,y1);
    x=y1; y=x1-(a/b)*y1;
    return d;

}

bool anySol(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    g=exGCD(abs(a),abs(b),x0,y0);
    if(c%g){
        return false;
    }
    x0*=c/g;
    y0*=c/g;
    if(a<0)x0=-x0;
    if(b<0)y0=-y0;
    return true;
}

int main()
{
    ll a,b,c,x,y,g;
    cin>>a>>b>>c;
    bool ck=anySol(a,b,c,x,y,g);
    if(ck){
        cout<<x<<"*"<<a<<" + "<<y<<"*"<<b<<" = "<<c<<endl;
    }else{
        cout<<"No solutions."<<endl;
    }
}
