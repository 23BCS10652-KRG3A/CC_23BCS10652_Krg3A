#include<iostream>
using namespace std;

int singleNumber(int arr[],int n){
int result=0;
for(int i=0;i<32;i++){
int sum=0;
for(int j=0;j<n;j++){
if((arr[j]>>i)&1)sum++;
}
if(sum%3!=0)result=result|(1<<i);
}
return result;
}

int main(){
int arr[]={2,2,3,2};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<singleNumber(arr,n);
}
