#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+5];
int n,res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int mx=-500;mx<=500;mx++) {
        int cur=0,len=0;
        for (int i=1;i<=n;i++) {
            if (a[i]<=mx) {
                cur+=a[i];
                len++;
                if (cur<0) {
                    cur=0;
                    len=0;
                }
            } else {
                cur=0;
                len=0;
            }
            if (len!=0) res=max(res,cur-mx);
        }
    }
    cout<<res;
}
