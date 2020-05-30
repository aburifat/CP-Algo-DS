/*******Bismillahir-Rahmanir-Rahim**********/
/*
Name         : Abu Rifat Muhammed Al Hasib
Institution  : University of Barisal, Bangladesh
Github       : abu-rifat
Codeforces   : AbuRifatMuhammed
AtCoder      : aburifat
codechef     : aburifat
SPOJ         : abu_rifat
UvaOJ        : aburifat
DevSkill     : abu_rifat
lightoj      : Abu Rifat Muhammed Al Hasib
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com
*/

/*
Algorithm    : Fibonacci Number with Binary Exponentiation
complexity   : O(logn), where calculating n-th Fibonacci Number.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0,1};

    auto p = fib(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = (p.first * p.first + p.second * p.second);
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main()
{
    ll n;
    cin>>n;
    pair<ll,ll>ans=fib(n);
    cout<<"n-th fib : "<<ans.first<<endl;
    cout<<"(n+1)-th fib : "<<ans.second<<endl;
    return 0;
}



/***********Alhamdulillah***********/
