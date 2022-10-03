#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxCircularSubArraySum(vector<ll>& nums) {
    ll maxSum=INT_MIN, minSum=INT_MAX;
    ll currMax,currMin,totSum,maxVal;
    currMax=currMin=totSum=maxVal=nums[0];
    for(ll i=1;i<nums.size();i++){
        currMax=max(nums[i],currMax+nums[i]);
        maxSum=max(maxSum,currMax);
        currMin=min(nums[i],currMin+nums[i]);
        minSum=min(minSum,currMin);
        totSum+=nums[i];
        maxVal=max(maxVal,nums[i]);
    }
    return (maxVal<0)? maxVal:max(maxSum,totSum-minSum);
}

int main(){
    vector<ll>arr={8,-8,9,-9,10,-11,12};
    ll ans=maxCircularSubArraySum(arr);
    cout<<ans<<endl;
    return 0;
}
