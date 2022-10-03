#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1000010;

ll sumDiv(ll n) {
    ll ans=1;
    for(ll i=2; i<=n; i++) {
        if(n%i==0) {
            ll power=1;
            while(n%i==0) {
                n/=i;
                power++;
            }
            ans*=(powl(i,power)-1)/(i-1);
        }
    }
    return ans;
}


int main()
{
    cout<<sumDiv(12)<<endl;
    return 0;
}

