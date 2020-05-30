#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>par;
ll node, edge;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCycCon(int s)
{
    par.assign(node+1,-1);

    queue<ll>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
                par[v]=u;
            }
            else if(par[u]!=v)
                return true;
        }
    }
    return false;
}


bool isCycDis()
{
    visited.assign(node+1,false);

    for(ll i=0;i<node;i++){
        if(!visited[i]&&isCycCon(i))
            return true;
        return false;
    }
}

int main()
{
    node = 4;
    adj.assign(node+1,vector<ll>());
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);

    if (isCycDis())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
