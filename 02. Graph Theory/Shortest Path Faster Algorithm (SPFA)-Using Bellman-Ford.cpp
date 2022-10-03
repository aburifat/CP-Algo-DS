#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=LONG_MAX;

ll node, edge, weight;
vector<vector<pair<ll,ll> > >adj;
vector<ll>dis,par,cnt;
vector<bool>inQueue;

void inis() {
    adj.assign(node+1,vector<pair<ll,ll> >());
    cnt.assign(node+1,0);
    dis.assign(node+1,MX);
    par.assign(node+1,-1);
    inQueue.assign(node+1,false);
}

void addEdge(ll u, ll v, ll w) {
    adj[u].push_back({v,w});
    adj[v].push_back({u,w}); ///for undirected or bidirectional graph
}

bool spfa(ll s) {
    queue<ll> q;

    dis[s] = 0;
    q.push(s);
    inQueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        inQueue[v] = false;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                par[to] = v;
                if (!inQueue[to]) {
                    q.push(to);
                    inQueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > node)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}

vector<ll> getPath(ll s, ll t) {
    vector<ll>path;
    for(ll v=t; v!=s; v=par[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}

int main() {
    cin>>node>>edge;
    inis();
    ll a,b;
    for(ll i=0; i<edge; i++) {
        cin>>a>>b>>weight;
        addEdge(a,b,weight);
    }
    bool notCyc=spfa(0);
    if(!notCyc)
        cout<<"Negative Cycle Found!!"<<endl;
    else {
        for(ll i=0; i<node; i++) {
            cout<<"Distance of node "<<i<<" from node 0 : "<<dis[i]<<endl;
            vector<ll>path=getPath(0,i);
            cout<<"The path is :: ";
            for(ll j=0; j<path.size(); j++) {
                cout<<path[j]<<" ";
            }
            cout<<endl;
        }
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
2 3 -1
4 0 1
3 0 1

output::

Distance of node 0 from node 0 : 0
The path is :: 0
Distance of node 1 from node 0 : 2
The path is :: 0 4 1
Distance of node 2 from node 0 : 3
The path is :: 0 4 1 2
Distance of node 3 from node 0 : 1
The path is :: 0 3
Distance of node 4 from node 0 : 1
The path is :: 0 4

**/
