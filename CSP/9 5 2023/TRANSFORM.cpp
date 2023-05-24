#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("TRANSFORM.INP","r",stdin);
    freopen("TRANSFORM.OUT","w",stdout);
    int n,res=1;
    cin>>n;
    if (n==0) res=0;
    while (n>=10) {
        int t=n;
        int mx=0;
        while (t>0) {
            mx=max(mx,t%10);
            t/=10;
        }
        n-=mx;
        res++;
    }
    cout<<res;
}
