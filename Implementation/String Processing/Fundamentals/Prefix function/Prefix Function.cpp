#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>prefFunc(string s){
    ll len=s.size();
    vector<ll>pi(len);
    for (ll i=1;i<len;i++) {
        ll j=pi[i-1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}

int main()
{
    string s="abcsdabck";
    vector<ll>pi=prefFunc(s);
    for(auto u:pi)
        cout<<u<<" ";
    cout<<endl;
}
