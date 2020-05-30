#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll>parent,siz;

void make_set(ll v)
{
    parent[v]=v;
    siz[v]=1;
}

ll find_set(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b])
            swap(a,b);
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

