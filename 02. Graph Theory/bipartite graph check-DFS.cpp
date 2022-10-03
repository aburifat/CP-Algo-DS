#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>color;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBip(ll s)
{
    for(auto u : adj[s]){
        if(visited[u]==false){
            visited[u]=true;
            color[u]=!color[s];
            if(!isBip(u))
                return false;
        }
        else if(color[u]==color[s])
            return false;
    }
    return true;
}


int main()
{
    ll node=6;
    //cin>>node;
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    color.assign(node+1,0);

    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 1);

    bool ck=true;
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            visited[i]=true;
            color[i]=0;
            if(!isBip(i)){
                ck=false;
                break;
            }
        }
    }
    if(ck)cout<<"Graph is Bipartite"<<endl;
    else cout<<"Graph is not Bipartite"<<endl;
    return 0;
}

