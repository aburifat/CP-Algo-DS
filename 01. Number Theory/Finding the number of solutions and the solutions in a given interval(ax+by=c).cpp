#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(a==0){
        x=0;y=1;
        return b;
    }
    ll x1,y1;
    ll d=exGCD(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

bool findAny(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
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

void shiftSol(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll countAll(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    if(a==0&&b==0){
        return 0;
    }else if(a==0||b==0){
        ll x,y;
        ll g=exGCD(a,b,x,y);
        if(c%g)return 0;
        else return 1;
    }
    ll x, y, g;
    if (!findAny(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shiftSol(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shiftSol(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shiftSol(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shiftSol(x, y, a, b, -sign_b);
    ll rx1 = x;

    shiftSol(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shiftSol(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shiftSol(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shiftSol(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}


int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll cnt=countAll(a,b,c,0,1000,0,1000);
    cout<<cnt<<endl;
    return 0;
}
