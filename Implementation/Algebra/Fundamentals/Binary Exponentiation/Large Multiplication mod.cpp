#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

int main()
{
    ll b=12345898761;
    ll a=23123434884395;
    ll mod=34;
    cout<<bigMul(a,b,mod)<<endl;
    return 0;
}
