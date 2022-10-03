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

int main()
{
    ll a=0,b=2;
    ll g=gcd(a,b);
    cout<<g<<endl;
    return 0;
}
