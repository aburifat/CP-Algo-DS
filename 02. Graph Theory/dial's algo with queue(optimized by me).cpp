#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge, source, base=1;//index base
ll k;//max weight

vector<vector<pair<ll,ll> > >adj;
vector<queue<ll> >buckets;
vector<ll>dis,par;

inline void addEdge(ll u, ll v, ll w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

inline void printpath(ll u)
{
    if(u==-1)return;
    else{
        printpath(par[u]);
        cout<<u<<" -> ";
    }
}

inline ll next_bucket()
{
    for(ll i=0;i<=k; i++){
        if(!buckets[i].empty())return i;
    }
    return -1;
}

inline void inis()
{
    adj.assign(node+1,vector<pair<ll,ll> >());
    dis.assign(node+1,INT_MAX);
    par.assign(node+1,-1);
}

void dial()
{
    buckets.assign(k+2, queue<ll>());
    dis[source]=0;
    buckets[0].push(source);
    ll bkt=0;
    while(1)
    {
        ll s;
        while(!buckets[bkt].empty()){
            s=buckets[bkt].front();
            buckets[bkt].pop();
            for(auto e:adj[s]){
                ll v=e.first;
                ll w=e.second;
                if(dis[s]+w<dis[v]){
                    dis[v]=dis[s]+w;
                    par[v]=s;
                    buckets[w].push(v);
                }
            }
        }
        bkt=next_bucket();
        if(bkt==-1)break;
    }
}

int main()
{
    cin>>node>>edge>>source;
    inis();
    ll u,v,w;
    k=0;
    for(ll i=0; i<edge; i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        k=max(k,w);
    }
    dial();
    for(ll i=(0+base);i<(node+base);i++)cout<<"Minimum Distance from: "<<source<<", to: "<<i<<" : "<<dis[i]<<endl;
    cout<<endl;
    for(ll i=(0+base);i<(node+base);i++){
        cout<<"Shortest Path from: "<<source<<", to: "<<i<<" : "<<endl;
        printpath(par[i]);
        cout<<i<<endl;
    }
    return 0;
}
