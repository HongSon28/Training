#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int a[N+5];
int res,cur;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        if (a[i]>=a[i-1]) cur++;
        else cur=1;
        res=max(res,cur);
    }
    cout<<res;
}
