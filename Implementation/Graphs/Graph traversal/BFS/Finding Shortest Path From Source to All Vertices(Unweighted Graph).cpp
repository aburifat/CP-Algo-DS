#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back

vector<bool>visited;
vector<ll>dist,par; ///distence, parent
vector<vector<ll> >adj;

void addEdge(ll u, ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void bfs(ll s)
{
    dist[s]=0;
    //par[s]=-1;
    visited[s]=true;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll s=q.front();
        q.pop();
        ll d=dist[s];
        for(auto u=adj[s].begin();u!=adj[s].end();u++)
        {
            if(!visited[*u]){
                visited[*u]=true;
                dist[*u]=d+1;
                par[*u]=s;
                q.push(*u);
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
    ll node,edge,source;
    cin>>node>>edge>>source;
    visited.assign(node+1,false);
    dist.assign(node+1,LONG_MAX);
    par.assign(node+1,-1);
    adj.assign(node+1,vector<ll>());

    ll a,b;
    for(ll i=0; i<edge; i++)
    {
        cin>>a>>b;
        addEdge(a,b);
    }
    bfs(source);
    int base=0;
    ///base=1; ///for 1 based nodes....
    for(ll i=(0+base);i<(node+base);i++){
        cout<<"Minimum Distance from: "<<source<<", to: "<<i<<" : "<<dist[i]<<endl;
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
0 1
0 2
5 1
3 1
2 4
3 4
3 6
5 6
6 7
4 9
8 9
7 8

Output::

Minimum Distance from: 0, to: 0 : 0
Minimum Distance from: 0, to: 1 : 1
Minimum Distance from: 0, to: 2 : 1
Minimum Distance from: 0, to: 3 : 2
Minimum Distance from: 0, to: 4 : 2
Minimum Distance from: 0, to: 5 : 2
Minimum Distance from: 0, to: 6 : 3
Minimum Distance from: 0, to: 7 : 4
Minimum Distance from: 0, to: 8 : 4
Minimum Distance from: 0, to: 9 : 3

Shortest Path from: 0, to: 0 :
0
Shortest Path from: 0, to: 1 :
0 -> 1
Shortest Path from: 0, to: 2 :
0 -> 2
Shortest Path from: 0, to: 3 :
0 -> 1 -> 3
Shortest Path from: 0, to: 4 :
0 -> 2 -> 4
Shortest Path from: 0, to: 5 :
0 -> 1 -> 5
Shortest Path from: 0, to: 6 :
0 -> 1 -> 5 -> 6
Shortest Path from: 0, to: 7 :
0 -> 1 -> 5 -> 6 -> 7
Shortest Path from: 0, to: 8 :
0 -> 2 -> 4 -> 9 -> 8
Shortest Path from: 0, to: 9 :
0 -> 2 -> 4 -> 9


**/
