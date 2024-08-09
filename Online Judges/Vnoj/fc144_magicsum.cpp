#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long res=0;
    long long a[n+1],b[n+1];
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=n;i++) {
        res+=(a[i]+b[i])*(b[i]-a[i]+1)/2;
    }
    cout<<res;
}
