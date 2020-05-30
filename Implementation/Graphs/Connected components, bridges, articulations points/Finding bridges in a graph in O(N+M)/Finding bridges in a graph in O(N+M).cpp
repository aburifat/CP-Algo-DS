#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> > adj;
vector<bool>visited;
vector<ll>timeIn, low;
ll timer;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void useBridge(ll u, ll v)
{
    cout<<"Bridge found : "<<u<<" <-> "<<v<<endl;
}

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    timeIn[v] = low[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], timeIn[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > timeIn[v])
                useBridge(v, to);
        }
    }
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1, false);
    timeIn.assign(node+1, -1);
    low.assign(node+1, -1);
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
    timer = 0;
    for (ll i = 0; i < node; ++i) {
        if (!visited[i])
            dfs(i);
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
4 0
3 4
4 5
7 4
5 7
5 6
7 6

output::

Bridge found : 4 <-> 3
Bridge found : 0 <-> 4

**/
