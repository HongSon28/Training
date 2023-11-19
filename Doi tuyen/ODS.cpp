#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b;
long long calc(long long n) {
    if (n==0) return 0;
    if (n%2==1) return (n+1)*(n+1)/4+calc(n/2);
    return n*n/4+calc(n/2);
}
int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b;
        cout<<calc(b)-calc(a-1)<<endl;
    }
}
