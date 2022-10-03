#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;

ll n, arr[MX+10], sTree[3*MX+10];

void build(ll v, ll l, ll r)
{
    if(l==r) sTree[v]=arr[l];
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        sTree[v]=sTree[left]+sTree[right];
    }
}

ll Query(ll v, ll l, ll r, ll ql, ll qr)
{
    if(ql>qr)return 0;
    if(ql==l&&qr==r)return sTree[v];
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    ll p=Query(left,l,mid,ql,min(qr,mid));
    ll q=Query(right,mid+1,r,max(ql,mid+1),qr);
    ll ans=p+q;
    return ans;
}

void update(ll v, ll l,ll r, ll pos, ll val)
{
    if(l==r)sTree[v]=val;
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        if(pos<=mid)update(left,l,mid,pos,val);
        else update(right,mid+1,r,pos,val);
        sTree[v]=sTree[left]+sTree[right];
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
            ll ans=Query(1,1,n,ql,qr);
            cout<<ans<<endl;
        }else if(tp=='u'){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
}
