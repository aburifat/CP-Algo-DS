#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;

vector<vector<int> >adj;
int n;
int s;


void BFS()
{
    queue<int>q;
    vector<bool>used(n+1);
    vector<int>d(n+1),p(n+1);
    q.push(s);
    used[s]=true;
    p[s]=-1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u : adj[v]){
            if(!used[u]){
                used[u]=true;
                q.push(u);
                d[u]=d[v]+1;
                p[u]=v;
            }
        }

    }
}
