#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge,source;
vector<vector<pair<ll,ll> > >adj;
vector<bool>visited;
vector<ll>dis,par;

void addEdge(ll u, ll v, ll w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}


void bfs(ll s)
{
    dis[s]=0;
    deque<ll>q;
    q.push_front(s);
    while(!q.empty()){
        s=q.front();
        q.pop_front();
        for(auto edge:adj[s]){
            ll v=edge.first;
            ll w=edge.second;
            if(dis[s]+w<dis[v]){
                dis[v]=dis[s]+w;
                par[v]=s;
                if(w==1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}



void printpath(ll u)
{
    if(u==-1)return;
    else{
        printpath(par[u]);
        cout<<u<<" -> ";
    }
}

int main()
{
    cin>>node>>edge>>source;
    visited.assign(node+1,false);
    dis.assign(node+1,LONG_MAX);
    par.assign(node+1,-1);
    adj.assign(node+1,vector<pair<ll,ll> >());

    ll u,v,w;
    for(ll i=0; i<edge; i++)
    {
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    bfs(source);
    int base=0;
    ///base=1; ///for 1 based nodes....
    for(ll i=(0+base);i<(node+base);i++){
        cout<<"Minimum Distance from: "<<source<<", to: "<<i<<" : "<<dis[i]<<endl;
    }
    cout<<endl;
    for(ll i=(0+base);i<(node+base);i++){
        cout<<"Shortest Path from: "<<source<<", to: "<<i<<" : "<<endl;
        printpath(par[i]);
        cout<<i<<endl;
    }
    return 0;
}

/**
Input::

10 12 0
0 1 1
0 2 0
5 1 1
3 1 1
2 4 0
3 4 0
3 6 1
5 6 1
6 7 0
4 9 0
8 9 0
7 8 1

*/
