#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<pair<ll,ll> > > adj;
vector<pair<ll,ll> >edges;
vector<bool>visited;
vector<ll>timeIn, low;
ll timer;


ll bridge_cnt,comp_cnt;
string orient;


void addEdge(ll idx, ll u, ll v)
{
    adj[u].push_back({v, idx});
    adj[v].push_back({u, idx});
    edges[idx] = {u, v};
}


void find_bridges(int v) {
    static int time = 0;
    low[v] = timeIn[v] = time++;
    for (auto p : adj[v]) {
        if (visited[p.second]) continue;
        visited[p.second] = true;
        orient[p.second] = v == edges[p.second].first ? '>' : '<';
        int nv = p.first;
        if (timeIn[nv] == -1) { // if nv is not visited yet
            find_bridges(nv);
            low[v] = min(low[v], low[nv]);
            if (low[nv] > timeIn[v]) {
                // a bridge between v and nv
                bridge_cnt++;
            }
        } else {
            low[v] = min(low[v], low[nv]);
        }
    }
}

void inis()
{
    adj.clear();
    adj.resize(node+1);
    timeIn.assign(node+1, -1);
    low.assign(node+1, -1);
    orient.resize(edge+1);
    edges.resize(edge+1);
    visited.assign(edge+1,false);
}

void read()
{
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0; i<edge;i++){
        cin>>a>>b; ///a,b must be 0 indexed
        addEdge(i,a,b);
    }
}

void printAns()
{
    printf("%lld\n%s\n", comp_cnt + bridge_cnt, orient.c_str());
}

void solve()
{
    comp_cnt = 0;
    for (ll v = 0; v < node; v++) {
        if (timeIn[v] == -1) {
            comp_cnt++;
            find_bridges(v);
        }
    }
    printAns();
}


int main() {
    read();
    solve();
    return 0;
}
