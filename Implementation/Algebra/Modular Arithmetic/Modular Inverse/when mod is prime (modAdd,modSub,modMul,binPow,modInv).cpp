#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod = 998244353;

ll modAdd(ll x, ll y) {
	x += y;
	if (x >= mod) return x - mod;
	return x;
}

ll modSub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + mod;
	return x;
}

ll modMul(ll x, ll y) {
	return (x * y) % mod;
}

ll binPow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return modMul(x, binPow(x, p - 1));
	return binPow(modMul(x, x), p / 2);
}

ll modInv(ll x) {
	return binPow(x, mod - 2);
}

int main()
{
    ll a=5,b=3;
    cout<<modInv(a)<<" "<<modInv(b)<<endl;
    cout<<modMul(a,b)<<endl;
    cout<<modSub(a,b)<<endl;
    cout<<modAdd(a,b)<<endl;
    return 0;
}
