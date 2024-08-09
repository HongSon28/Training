#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int cur,res=N+5;
int a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        if (a[i]==1) {
            if (cur>=2) res=min(res,cur);
            cur=0;
        }
        else cur++;
    }
    if (cur>=2) res=min(res,cur);
    cout<<res;
}
