#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int sumHammingPairs(vector<int>& A) {
    long long ans = 0;
    int n = A.size();
    
    for(int bit=0;bit<32;bit++) {
        long long cnt1 = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] & (1 << bit)) cnt1++;
        }
        long long cnt0=n-cnt1;
        ans = (ans+(2LL*cnt1*cnt0)%MOD)%MOD;
    }
    return ans;
}

int main() {
    vector<int>A={2,7};
    cout<<sumHammingPairs(A)<<endl; 
}
