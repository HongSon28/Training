#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned a[100000];
    unsigned k;
    unsigned long long x;
    cin>>x>>k;
    unsigned dem=0;
    while (x>1) {
        if (x%k==0) {
            x/=k;
            a[dem]=1;
        } else {
            x+=1;
            a[dem]=2;
        }
        dem+=1;
    }
    cout<<dem<<endl;
    for (unsigned i=0;i<dem;i++) {
        cout<<a[i]<<" ";
    }
}
