#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> > adj;
vector<bool>visited;
vector<ll>timeIn, low;
ll timer;
set<ll>cutPoints;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void useCutPoint(ll v) {
    cutPoints.insert(v);
}

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    timeIn[v] = low[v] = timer++;
    ll children=0;
    for (ll to : adj[v]) {
        if (to == p)
            continue;
        if (visited[to]) {
            low[v] = min(low[v], timeIn[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= timeIn[v] && p!=-1) {
                useCutPoint(v);
            }
            ++children;
        }
    }
    if(p==-1 && children>1)
        useCutPoint(v);
}

void inis() {
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1, false);
    timeIn.assign(node+1, -1);
    low.assign(node+1, -1);
}

void read() {
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0; i<edge; i++) {
        cin>>a>>b;
        addEdge(a,b);
    }
}

void printAns() {
    ll len=cutPoints.size();
    cout<<"Total Number of Cut Points :: "<<len<<endl;
    for(auto v:cutPoints) {
        cout<<"Cut Point : "<<v<<endl;
    }
}

void solve() {
    timer = 0;
    for (ll i = 0; i < node; ++i) {
        if (!visited[i])
            dfs(i);
    }
    printAns();
}

int main() {
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

