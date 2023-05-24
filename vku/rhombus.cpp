#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long res=0;
    long long j=1;
    for(long long i=1;i<=n;i++) {
        res+=j*2;
        j+=2;
    }
    res+=j;
    cout<<res;
}
