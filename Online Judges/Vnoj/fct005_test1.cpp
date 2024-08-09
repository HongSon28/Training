#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,t,res,mx;
int a[N+5];
int main() {
    cin>>n;
    while (n--) {
        cin>>t;
        a[t]++;
    }
    for (int i=1;i<=N;i++) {
        if (a[i]>mx) {
            mx=a[i];
            res=i;
        }
    }
    cout<<res;
}
