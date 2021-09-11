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
website		 : https://aburifat.com
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com, abu.rifat.m@gmail.com
*/

/*
Algorithm    : Binary Exponentiation
complexity   : O(logn), where n is the power.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power)
{
    ll result=1;
    while(power>0){
        if(power&1)result*=base;
        base*=base;
        power>>=1;
    }
    return result;
}

int main()
{
    ll base, power;
    cin>>base>>power;
    ll ans=binpow(base,power);
    cout<<"base^power = "<<ans<<endl;
    return 0;
}

/***********Alhamdulillah***********/
