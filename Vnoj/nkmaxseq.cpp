#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n,p,sum=0,len=0,res=-1;
    cin>>n>>p;
    ll a[n+5];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++) {
        sum+=a[i];
        len++;
        if (sum>=p&&len!=0)
            res=max(res,len);
        if (sum<0) {
            sum=0;
            len=0;
        }
    }
    cout<<res;
}
