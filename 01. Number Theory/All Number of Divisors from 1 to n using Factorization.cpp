#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>nod;

ll nodAll(ll n) {
    nod.resize(n+1);
    nod[0]=0;
    nod[1]=1;
    for(ll i=2; i<=n; i++)
        nod[i]=1;
    for(ll i=2; i<=n; i++) {
        if(nod[i]==1) {
            for(ll j=i; j<=n; j+=i) {
                ll power=0;
                ll val=i;
                while(j%val==0) {
                    power++;
                    val*=i;
                }
                nod[j]*=(power+1);
            }
        }
    }
}

int main() {
    nodAll(100000);
    cout<<nod[10]<<endl;
    return 0;
}

