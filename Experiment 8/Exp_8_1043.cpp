#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int maxSumAfterPartitioning(vector<int>& a,int k){
int n=a.size();
vector<int>dp(n+1,0);
for(int i=1;i<=n;i++){
int mx=0;
for(int j=1;j<=k&&i-j>=0;j++){
mx=max(mx,a[i-j]);
dp[i]=max(dp[i],dp[i-j]+mx*j);
}
}
return dp[n];
}
};

int main(){
int n,k;
cin>>n>>k;
vector<int>a(n);
for(int i=0;i<n;i++)cin>>a[i];
Solution s;
cout<<s.maxSumAfterPartitioning(a,k);
return 0;
}
