#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>component;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(ll s) {
    visited[s]=true ;
    component.push_back(s);
    for (auto u:adj[s]) {
        if (!visited[u])
            dfs(u);
    }
}

void useComponent()
{
    ll len=component.size();
    cout<<"Found Component :: ";
    for(ll i=0;i<len;i++)
        cout<<component[i]<<" ";
        cout<<endl;
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    component.clear();
}

void read()
{
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0; i<edge; i++){
        cin>>a>>b;
        addEdge(a,b);
    }
}

void solve()
{
    for(ll i=0;i<node;++i)
        visited[i]=false;
    for(ll i=0;i<node;++i)
        if(!visited[i]){
            dfs(i);
            useComponent();
            component.clear();
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

8 9
1 2
3 1
2 3
4 0
4 5
7 4
5 7
5 6
7 6

output::

Found Component :: 0 4 5 7 6
Found Component :: 1 2 3

**/
