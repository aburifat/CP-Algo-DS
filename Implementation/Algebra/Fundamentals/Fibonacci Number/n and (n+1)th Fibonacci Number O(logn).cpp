#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

constexpr ll mod=1e9+7;

pair<ll, ll> fib (ll n,ll mod) {
    if (n == 0)
        return {0,1};

    auto p = fib(n >> 1,mod);
    ll c = (p.F%mod * (2 * p.S - p.F+mod)%mod)%mod;
    ll d = ((p.F * p.F)%mod + (p.S * p.S)%mod)%mod;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main()
{
    pair<ll,ll>ans=fib(100,mod);
    cout<<ans.F<<" "<<ans.S<<endl;
    return 0;
}
