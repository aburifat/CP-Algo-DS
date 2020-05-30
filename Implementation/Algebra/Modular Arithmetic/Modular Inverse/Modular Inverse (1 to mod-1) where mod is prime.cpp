#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>inv;

void modInv(ll m)
{
    inv.resize(m+1);
    inv[1]=1;
    for(ll i=2;i<m;i++){
        inv[i]=(m-(m/i)*inv[m%i]%m)%m;
    }
}

int main()
{
    ll m=31;
    modInv(m);
    for(ll i=1;i<m;i++){
        cout<<i<<" "<<inv[i]<<endl;
    }
    return 0;
}
