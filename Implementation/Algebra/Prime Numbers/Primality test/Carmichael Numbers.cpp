#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll mod(ll x, ll n, ll p)
{
    if(n==1)return x%p;
    ll ans=mod(x,n/2,p);
    ans=(ans*ans)%p;
    if(n%2==1)return ans*x%p;
    return ans;
}

int main()
{
    ll n;
    sieve(MX);
    while(cin>>n){
        if(n==0)break;
        ll flag=1;
        if(!bs[n]){
            for(ll i=2;i<n;i++){
                if(mod(i,n,n)!=i){
                    flag=0;
                    break;
                }
            }
        }
        if(flag&&!bs[n]){
            cout<<"CM"<<endl;
        }else{
            cout<<"Normal"<<endl;
        }
    }
    return 0;
}
