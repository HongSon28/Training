#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n;
    cin>>n;
    ll a[n+1];
    ll res=0,len=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        if (a[i-1]!=a[i]) {
            len++;
        }
        res+=len;
    }
    cout<<res;
}
