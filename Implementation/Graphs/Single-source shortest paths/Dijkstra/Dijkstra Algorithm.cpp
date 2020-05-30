#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=LONG_MAX;
vector<vector<pair<ll,ll> > >adj;
vector<bool>visited;
vector<ll>dis,par;

ll node, edge, weight;

void inis()
{
    adj.assign(node+1,vector<pair<ll,ll> >());
    visited.assign(node+1,false);
    dis.assign(node+1,MX);
    par.assign(node+1,-1);
}

void addEdge(ll u, ll v, ll w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w}); ///for undirected or bidirectional graph
}

void dijkstra(ll s)
{
    dis[s]=0;
    for(ll i=0; i<node; i++){
        ll v=-1;
        for(ll j=0; j<node; j++){
            if(!visited[j]&&(v==-1||dis[j]<dis[v])){
                v=j;
            }
        }

        if(dis[v]==MX)break;

        visited[v]=true;
        for(auto edge : adj[v]){
            ll to=edge.first;
            ll len=edge.second;

            if(dis[v]+len<dis[to]){
                dis[to]=dis[v]+len;
                par[to]=v;
            }
        }
    }
}

vector<ll> getPath(ll s, ll t)
{
    vector<ll>path;
    for(ll v=t;v!=s;v=par[v]){
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}

int main()
{
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0; i<edge;i++){
        cin>>a>>b>>weight;
        addEdge(a,b,weight);
    }
    dijkstra(0);
    for(ll i=0; i<node;i++){
        cout<<"Distance of node "<<i<<" from node 0 : "<<dis[i]<<endl;
        vector<ll>path=getPath(0,i);
        cout<<"The path is :: ";
        for(ll j=0;j<path.size();j++){
            cout<<path[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**
input::

5 7
1 2 1
1 4 1
1 0 3
2 4 3
2 3 3
4 0 1
3 0 1

**/
