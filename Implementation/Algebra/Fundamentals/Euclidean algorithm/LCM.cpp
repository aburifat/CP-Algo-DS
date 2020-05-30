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

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    ll a=129,b=2243;
    ll g=gcd(a,b);
    ll l=lcm(a,b);
    cout<<g<<" "<<l<<endl;
    return 0;
}

