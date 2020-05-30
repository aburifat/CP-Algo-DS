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
        sTree[v]=max(sTree[left],sTree[right]);
    }
}

ll sumQ(ll v, ll l, ll r, ll ql, ll qr)
{
    if(ql>qr)return LONG_MIN;
    if(ql==l&&qr==r)return sTree[v];
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    ll p=sumQ(left,l,mid,ql,min(qr,mid));
    ll q=sumQ(right,mid+1,r,max(ql,mid+1),qr);
    ll ans=max(p,q);
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
        sTree[v]=max(sTree[left],sTree[right]);
    }
}

ll get_first(ll v, ll l, ll r, ll ql, ll qr, ll x) {
    if(l>qr||r<ql) return -1;
    if(ql<=l&&r<=qr){
        if(sTree[v]<=x) return -1;
        while(l!=r){
            ll left=v*2;
            ll right=left+1;
            ll mid=l+(r-l)/2;
            if(sTree[left]>x){
                v=left;
                r=mid;
            }else{
                v=right;
                l=mid+1;
            }
        }
        return l;
    }
    ll left=v*2;
    ll right=left+1;
    int mid=l+(r-l)/2;
    int rs=get_first(left,l,mid,ql,qr,x);
    if(rs!=-1) return rs;
    return get_first(right,mid+1,r,ql,qr,x);
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
    ll ql, qr, pos, val, x;
    for(ll i=1;i<=q;i++){
        cin>>tp;
        if(tp=='q'){
            cin>>ql>>qr>>x;
            if(ql>qr)swap(ql,qr);
            ll idx=get_first(1,1,n,ql,qr,x);
            cout<<idx<<endl;
        }else if(tp=='u'){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
    return 0;
}


