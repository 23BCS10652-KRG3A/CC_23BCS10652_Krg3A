#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
int n;
cin>>n;

vector<string>a(n);
for(int i=0;i<n;i++)cin>>a[i];

vector<vector<int> >adj(26);
vector<int>indegree(26,0);

for(int i=0;i<n-1;i++){
string s1=a[i];
string s2=a[i+1];

int len=min(s1.size(),s2.size());
int flag=0;

for(int j=0;j<len;j++){
if(s1[j]!=s2[j]){
adj[s1[j]-'a'].push_back(s2[j]-'a');
indegree[s2[j]-'a']++;
flag=1;
break;
}
}

if(flag==0 && s1.size()>s2.size()){
cout<<"Impossible";
return 0;
}
}

queue<int>q;
for(int i=0;i<26;i++){
if(indegree[i]==0)q.push(i);
}

string ans="";

while(!q.empty()){
int node=q.front();
q.pop();
ans+=(char)(node+'a');

for(int i=0;i<adj[node].size();i++){
int next=adj[node][i];
indegree[next]--;
if(indegree[next]==0)q.push(next);
}
}

if(ans.size()!=26){
cout<<"Impossible";
}
else{
cout<<ans;
}
}
