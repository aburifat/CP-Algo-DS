#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
stack<ll>st;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

void topoSort(ll s)
{
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            topoSort(u);
        }
    }
    st.push(s);
}

int main()
{
    cin>>node>>edge;
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    while(!st.empty()){
        st.pop();
    }
    ll a,b;
    for(ll i=0;i<edge;i++){
        cin>>a>>b;
        addEdge(a,b);
    }
    for(ll i=0;i<node;i++){
        if(!visited[i]){
            topoSort(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n"<<endl;
    return 0;
}

/**
input::

6 6

5 2
5 0
4 0
4 1
2 3
3 1


output::

5 4 2 3 1 0

**/
