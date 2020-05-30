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

ll sum_ct(ll v, ll l, ll r, ll ql, ll qr)
{
    if(ql>qr)return 0;
    if(ql==l&&qr==r)return sTree[v];
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    ll p=sum_ct(left,l,mid,ql,min(qr,mid));
    ll q=sum_ct(right,mid+1,r,max(ql,mid+1),qr);
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

ll find_pref_idx(ll v, ll l, ll r, ll k)
{
    if(k>sTree[v])return -1;
    if(l==r) return l;
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    if(sTree[left]>=k)
        return find_pref_idx(left,l,mid,k);
    else
        return find_pref_idx(right,mid+1,r,k-sTree[left]);
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
    ll pos, val, x;
    for(ll i=1;i<=q;i++){
        cin>>tp;
        if(tp=='u'){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }else if(tp='q'){
            cin>>x;
            ll idx=find_pref_idx(1,1,n,x);
            ll sum=-1;
            if(idx!=-1)sum=sum_ct(1,1,n,1,idx);
            cout<<"kth : "<<x<<" "<<idx<<" "<<sum<<endl;
        }
    }
}


