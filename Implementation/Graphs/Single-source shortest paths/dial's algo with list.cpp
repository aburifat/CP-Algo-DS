#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N=1e4+10; // maximum number of nodes
ll max_weight=100;
ll node, edges, source, base=1; //index base 1 or 0
vector<vector<pair<ll,ll> > >adj;
vector<list<ll> >buckets;
vector<list<ll>::iterator >it;
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

inline ll next_bucket(ll idx)
{
    for(int i=idx;i<=max_weight*node;i++){
        if(buckets[i].size())return i;
    }
    return -1;
}

inline void inis()
{
    adj.assign(node+1,vector<pair<ll,ll> >());
    dis.assign(node+1,max_weight*node+1);
    par.assign(node+1,-1);
    buckets.assign(max_weight*N, list<ll>());
    it.resize(N, list<ll>::iterator());
}

void dial()
{

    for(ll i=base; i<node+base;i++){
        if(i!=source){
            buckets[dis[i]].push_back(i);
            it[i]=--buckets[dis[i]].end();//memory location for node i in the buckets
        }
    }
    dis[source]=0;
    buckets[0].push_back(source); //distence from source to source
    it[0]=buckets[0].begin();
    ll bkt=0;
    while(1){
        ll bkt=next_bucket(bkt);
        if(bkt==-1)break;
        ll s=*buckets[bkt].begin();
        buckets[bkt].erase(buckets[bkt].begin());
        for(auto edge:adj[s]){
            ll v=edge.first;
            ll w=edge.second;
            if(dis[s]+w<dis[v]){
                buckets[dis[v]].erase(it[v]);
                dis[v]=dis[s]+w;
                par[v]=s;
                buckets[dis[v]].push_back(v);
                it[v]=--buckets[dis[v]].end();
            }
        }

    }
}

int main()
{
    cin>>node>>edges>>source;
    inis();
    ll u, v, w;
    for(ll i=0;i<edges;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    return 0;
}
