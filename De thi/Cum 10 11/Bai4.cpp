#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,res=0;
    cin>>n;
    for (long long i=1;i<=n;i+=2) {
        res+=i*i;
    }
    cout<<res;
}
