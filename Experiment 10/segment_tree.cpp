#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
int n;
vector<int>seg;

SegmentTree(vector<int>&a){
n=a.size();
seg.resize(4*n);
build(0,0,n-1,a);
}

void build(int idx,int l,int r,vector<int>&a){
if(l==r){
seg[idx]=a[l];
return;
}
int mid=(l+r)/2;
build(2*idx+1,l,mid,a);
build(2*idx+2,mid+1,r,a);
seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}

int query(int idx,int l,int r,int ql,int qr){
if(qr<l||ql>r)return 0;
if(ql<=l&&r<=qr)return seg[idx];
int mid=(l+r)/2;
return query(2*idx+1,l,mid,ql,qr)+query(2*idx+2,mid+1,r,ql,qr);
}

void update(int idx,int l,int r,int pos,int val){
if(l==r){
seg[idx]=val;
return;
}
int mid=(l+r)/2;
if(pos<=mid)update(2*idx+1,l,mid,pos,val);
else update(2*idx+2,mid+1,r,pos,val);
seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}
};

int main(){
int n,q;
cin>>n>>q;
vector<int>a(n);
for(int i=0;i<n;i++)cin>>a[i];
SegmentTree st(a);
while(q--){
int type;cin>>type;
if(type==1){
int pos,val;cin>>pos>>val;
st.update(0,0,n-1,pos,val);
}
else{
int l,r;cin>>l>>r;
cout<<st.query(0,0,n-1,l,r)<<endl;
}
}
return 0;
}
