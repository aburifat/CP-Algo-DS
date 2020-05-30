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

vector<ll>KMP(string pattern, string text)
{
    vector<ll>ans;
    string s=pattern+'#';
    ll pLen=pattern.size();
    ll tLen=text.size();
    vector<ll>pi=prefFunc(s);
    ll textPi=0;
    for(ll i=0;i<tLen;i++){
        ll j=textPi;
        while(j>0&&pattern[j]!=text[i])
            j=pi[j-1];
        if(pattern[j]=text[i])
            j++;
        textPi=j;
        if(textPi==(pLen)){
            ans.push_back(i-pLen+2);
        }
    }
    return ans;
}

int main()
{
    string pattern="abc";
    string text="abcnsabcaba";
    vector<ll>ans=KMP(pattern, text);
    for(auto u:ans)
        cout<<u<<" ";
    cout<<endl;
}


