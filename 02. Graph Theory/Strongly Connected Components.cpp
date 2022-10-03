#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj,revAdj;
vector<bool>visited;
vector<ll>order,component;

void dfs1(ll s)
{
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u])
            dfs1(u);
    }
    order.push_back(s);
}

void dfs2(ll s)
{
    visited[s]=true;
    component.push_back(s);
    for(auto u:revAdj[s]){
        if(!visited[u])
            dfs2(u);
    }
}

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

void useComponent()
{
    ll len=component.size();
    cout<<"Strongly Connected Component Found :: ";
    for(ll i=0; i<len; i++){
        cout<<component[i]+1<<" ";
    }
    cout<<endl;
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    revAdj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    order.clear();
    component.clear();
}

void read()
{
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0;i<edge;i++){
        cin>>a>>b;
        addEdge(a,b);
    }
}

void solve()
{
    for(ll i=0; i<node;++i){
        if(!visited[i])
            dfs1(i);
    }
    visited.assign(node+1,false);
    for(ll i=0; i<node;++i){
        ll s=order[node-1-i];
        if(!visited[s]){
            dfs2(s);
            useComponent();
            component.clear();
        }
    }
}

int main()
{
    read();
    solve();
    return 0;
}

/**

input::

8 10
1 2
3 1
2 3
3 4
4 0
4 5
7 4
5 7
5 6
7 6

output::

Strongly Connected Component Found :: 1 3 2
Strongly Connected Component Found :: 4 7 5
Strongly Connected Component Found :: 6
Strongly Connected Component Found :: 0

**/
