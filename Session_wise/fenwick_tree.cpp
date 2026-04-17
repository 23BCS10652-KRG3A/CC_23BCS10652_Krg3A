#include <bits/stdc++.h>
using namespace std;

class Fenwick{
public:
int n;
vector<int>bit;

Fenwick(int n){
this->n=n;
bit.assign(n+1,0);
}

void update(int i,int val){
for(;i<=n;i+=i&-i)bit[i]+=val;
}

int sum(int i){
int s=0;
for(;i>0;i-=i&-i)s+=bit[i];
return s;
}

int rangeSum(int l,int r){
return sum(r)-sum(l-1);
}
};

int main(){
int n,q;
cin>>n>>q;
Fenwick ft(n);
for(int i=1;i<=n;i++){
int x;cin>>x;
ft.update(i,x);
}
while(q--){
int type;cin>>type;
if(type==1){
int i,val;cin>>i>>val;
ft.update(i,val);
}
else{
int l,r;cin>>l>>r;
cout<<ft.rangeSum(l,r)<<endl;
}
}
return 0;
}
