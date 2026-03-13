#include <iostream>
#include <algorithm>
using namespace std;
int bts(int tokens[],int n,int p) {
    
    sort(tokens,tokens+n);   
    int l=0;
    int r=n-1;
    int s=0;
    int maxScore=0;

    while(l<=r) {

        if(p>=tokens[l]) { 
            p-=tokens[l];
            s++;
            l++;
            maxScore = max(maxScore,s);
        }

        else if(s>0) {
            p+=tokens[r];
            s--;
            r--;
        }

        else {
            break;
        }
    }

    return maxScore;
}

int main() {

    int tokens[] = {100,200,300,400};
    int n = sizeof(tokens)/sizeof(tokens[0]);
    int power = 200;

    cout << "Maximum Score: "<< bts(tokens,n,power);

    return 0;
}
