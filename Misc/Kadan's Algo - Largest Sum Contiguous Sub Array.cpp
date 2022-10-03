#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxSubArraySum(ll arr[], ll n)
{
    ll maxSoFar=arr[0];
    ll currMax=arr[0];

    for(ll i=0; i<n; i++)
    {
        currMax=max(arr[i],currMax+arr[i]);
        maxSoFar=max(maxSoFar,currMax);
    }
    return maxSoFar;
}

int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll max_sum=maxSubArraySum(arr,n);
    cout<<"Maximum Contiguous sum is "<<max_sum<<"\n";
    return 0;
}
