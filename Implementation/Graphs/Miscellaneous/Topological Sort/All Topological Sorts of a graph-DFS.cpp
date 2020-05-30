#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>inDegree;
vector<ll>res;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    inDegree[v]++;
}

void allTopoSort() {
    bool flag=false;
    for(ll i=1; i<=node; i++) {
        if(inDegree[i]==0&&!visited[i]) {
            for(auto j:adj[i]) {
                inDegree[j]--;
            }
            res.push_back(i);
            visited[i]=true;
            allTopoSort();
            visited[i]=false;
            res.erase(res.end()-1);
            for(auto j:adj[i]) {
                inDegree[j]++;
            }
            flag=true;
        }
    }
    if(!flag) {
        for(ll i=0; i<res.size(); i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}


int main() {
        cin>>node>>edge;
        adj.assign(node+1,vector<ll>());
        visited.assign(node+1,false);
        inDegree.assign(node+1,0);
        res.clear();
        ll a,b;
        for(ll i=0;i<edge;i++){
            cin>>a>>b;
            addEdge(a,b);
        }
        allTopoSort();
    return 0;
}

