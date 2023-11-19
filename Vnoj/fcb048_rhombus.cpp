#include<bits/stdc++.h>
using namespace std;
int main() {
    long long res=0;
    int n;
    long long t=1;
    cin>>n;
    for (int i=1;i<=n+1;i++) {
        res+=t*2;
        t+=2;
    }
    res-=t-2;
    cout<<res;
}
