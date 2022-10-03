#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX=1e5;

bitset<1000009>bs;
vector<ll>primes;

void sieve(ll ub)
{
    ub++;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3;i<=ub;i+=2){
        if(bs[i])
        {
            for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}

vector<ll>PF(ll n) {
    vector<ll>fact;
    for (auto d:primes) {
        if(d*d>n)break;
        while(n%d==0) {
            fact.push_back(d);
            n/=d;
        }
    }
    if(n>1)fact.push_back(n);
    return fact;
}


int main()
{
    sieve(MX);
    ll n=1024;
    vector<ll>ans=PF(n);
    for(auto u:ans)cout<<u<<" ";
    cout<<"\n";
    return 0;
}
