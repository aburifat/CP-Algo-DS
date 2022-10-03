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
Algorithm    : Binary Exponentiation
complexity   : O(logn), where n is the power.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

int main()
{
    ll base, power, mod;
    cin>>base>>power>>mod;
    ll ans=binpow(base,power,mod);
    cout<<"(base^power)%mod = "<<ans<<endl;
    return 0;
}

/***********Alhamdulillah***********/

