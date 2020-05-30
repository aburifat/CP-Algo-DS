#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<vector<ll> >adj,adjRev;
vector<bool>visited;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adjRev[v].push_back(u);
}

void bfs(ll s,ll st) {
    visited[s]=0;
    queue<ll>q;
    q.push(s);
    while(!q.empty()) {
        ll u=q.front();
        q.pop();
        if(!st) {
            for(auto v:adj[u]) {
                if(!visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }
        } else {
            for(auto v:adjRev[u]) {
                if(!visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }

        }
    }
}

bool isSC() {
    visited.assign(n+1,false);
    bfs(0,0);
    for(ll i=0; i<n; i++) {
        if(visited[i]==false) {
            return false;
        }
    }
    visited.assign(n+1,false);
    bfs(0,1);
    for(ll i=0; i<n; i++) {
        if(visited[i]==false) {
            return false;
        }
    }
    return true;
}

void inis()
{
    adj.assign(n+1,vector<ll>());
    adjRev.assign(n+1,vector<ll>());
}


int main() {
    n=5;
    inis();
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);
    addEdge(2, 4);
    addEdge(4, 2);
    isSC()? cout << "Yes\n" : cout << "No\n";

    n=4;
    inis();
    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    isSC()? cout << "Yes\n" : cout << "No\n";
    return 0;
}





