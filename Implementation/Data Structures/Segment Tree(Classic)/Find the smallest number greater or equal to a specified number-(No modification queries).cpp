#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(v) v.begin(),v.end()
#define pb push_back

const ll MX=100000;

ll n, arr[MX+10];
vector<ll> sTree[3*MX+10];

void build(ll v, ll l, ll r)
{
    if(l==r) sTree[v].pb(arr[l]);
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        merge(all(sTree[left]),all(sTree[right]),back_inserter(sTree[v]));
    }
}

ll Query(ll v, ll l, ll r, ll ql, ll qr, ll x)
{
    if(ql>qr)return LONG_MAX;
    if(ql==l&&qr==r){
        vector<ll>::iterator pos=lower_bound(all(sTree[v]),x);
        if(pos!=sTree[v].end())
            return *pos;
        return LONG_MAX;
    }
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    ll p=Query(left,l,mid,ql,min(qr,mid),x);
    ll q=Query(right,mid+1,r,max(ql,mid+1),qr,x);
    ll ans=min(p,q);
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    ll q;
    cin>>q;
    ll ql, qr, x;
    for(ll i=1;i<=q;i++){
        cin>>ql>>qr>>x;
        if(ql>qr)swap(ql,qr);
            ll ans=Query(1,1,n,ql,qr,x);
            if(ans==LONG_MAX)cout<<"Not Found In The Range"<<endl;
            else cout<<ans<<endl;
    }
    return 0;
}

