#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if(a==0){
        x=0;y=1;
        return b;
    }
    ll x1,y1;
    ll d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

bool findAny(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    if(a==0&&b==0){
        return false;
    }
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g){
        return false;
    }
    x0*=c/g;
    y0*=c/g;
    if(a<0)x0=-x0;
    if(b<0)y0=-y0;
    return true;
}

void findAll(ll a, ll b, ll c)
{
    ll x, y, g;
    bool ck=findAny(a,b,c,x,y,g);
    if(ck){
        cout<<x<<" "<<y<<endl;
        ll ct=100;
        while(ct--){
            x+=(b/g);
            y-=(a/g);
            cout<<x<<" "<<y<<endl;
        }
    }else{
        cout<<"No solutions."<<endl;
    }
}

int main()
{
    ll a,b,c,x,y,g;
    cin>>a>>b>>c;
    findAll(a,b,c);
    return 0;
}

