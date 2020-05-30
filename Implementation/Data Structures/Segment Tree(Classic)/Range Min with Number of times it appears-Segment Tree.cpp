#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;

ll n, arr[MX+10];
pair<ll,ll> sTree[3*MX+10];

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first < b.first)
        return a;
    if(b.first < a.first)
        return b;
    return {a.first,a.second+b.second};
}

void build(ll v, ll l, ll r)
{
    if(l==r) sTree[v] = {arr[l],1};
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        sTree[v]=combine(sTree[left],sTree[right]);
    }
}

pair<ll,ll> Query(ll v, ll l, ll r, ll ql, ll qr)
{
    if(ql>qr)return {LONG_MAX,0};
    if(ql==l&&qr==r)return sTree[v];
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    pair<ll,ll>p,q,ans;
    p=Query(left,l,mid,ql,min(qr,mid));
    q=Query(right,mid+1,r,max(ql,mid+1),qr);
    ans=combine(p,q);
    return ans;
}

void update(ll v, ll l,ll r, ll pos, ll val)
{
    if(l==r)sTree[v]={val,1};
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        if(pos<=mid)update(left,l,mid,pos,val);
        else update(right,mid+1,r,pos,val);
        sTree[v]=combine(sTree[left],sTree[right]);
    }
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
    char tp;
    ll ql, qr, pos, val;
    for(ll i=1;i<=q;i++){
        cin>>tp;
        if(tp=='q'){
            cin>>ql>>qr;
            if(ql>qr)swap(ql,qr);
            pair<ll,ll> ans=Query(1,1,n,ql,qr);
            cout<<"Min Value : "<<ans.first<<" appears : "<<ans.second<<" times."<<endl;
        }else if(tp=='u'){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
}

