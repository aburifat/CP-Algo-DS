#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll factmod(ll n,ll p) {
    int res=1;
    while (n>1) {
        res=(res*((n/p)%2?p-1:1))%p;
        for (ll i=2;i<=n%p;++i)
            res=(res*i)%p;
        n/=p;
    }
    return res%p;
}
