#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int res;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int mx=a[i],mn=a[i];
        if (mx==1) res++;
        for (int j=i+1;j<=n;j++) {
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
            if (__gcd(mx,mn)==1) res++;
        }
    }
    cout<<res;
}
