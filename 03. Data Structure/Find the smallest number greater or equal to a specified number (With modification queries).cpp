///Find the smallest number greater or equal to a specified number. With modification queries.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(v) v.begin(),v.end()

const ll MX=100000;

ll n, arr[MX+10];
multiset<ll> sTree[3*MX+10];

void build(ll v, ll l, ll r)
{
    if(l==r) sTree[v].insert(arr[l]);
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        merge(all(sTree[left]),all(sTree[right]),inserter(sTree[v],sTree[v].begin()));
    }
}

ll Query(ll v, ll l, ll r, ll ql, ll qr, ll x)
{
    if(ql>qr)return LONG_MAX;
    if(ql==l&&qr==r){
        multiset<ll>::iterator pos;
        pos=sTree[v].lower_bound(x);
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

void update(ll v, ll l, ll r, ll pos, ll val) {
    sTree[v].erase(sTree[v].find(arr[pos]));
    sTree[v].insert(val);
    if (l!=r) {
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        if (pos<=mid)
            update(left,l,mid,pos,val);
        else
            update(right, mid+1,r,pos,val);
    } else {
        arr[pos]=val;
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
    ll ql, qr, x, pos, val;
    string st;
    for(ll i=1;i<=q;i++){
            cin>>st;
        if(st=="q"){
            cin>>ql>>qr>>x;
        if(ql>qr)swap(ql,qr);
            ll ans=Query(1,1,n,ql,qr,x);
            if(ans==LONG_MAX)cout<<"Not Found In The Range"<<endl;
            else cout<<ans<<endl;
        }
        else if(st=="u"){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
    return 0;
}

/**

input:

10
2 7 1 2 4 0 1 -1 2 -6
4
q 4 6 3
u 4 3
q 4 6 3
q 1 10 5

Output:

**/

