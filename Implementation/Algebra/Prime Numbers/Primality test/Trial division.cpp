#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isPrime(ll x) {
    if(x==1)return false;
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main() {
    ll n;
    while(cin>>n) {
        string ans=(isPrime(n))?"Prime.\n":"Not Prime.\n";
        cout<<ans<<endl;
    }
    return 0;
}
