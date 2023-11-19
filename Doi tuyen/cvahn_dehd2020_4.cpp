#include<bits/stdc++.h>
using namespace std;
const int N=1e5,maxN=1e6;
int n,m,l=1,r=1,cnt=1,res;
int a[N+5];
int c[maxN+5];
int main() {
    cin>>n>>m;
    res=n;
    for (int i=1;i<=n;i++) cin>>a[i];
    c[a[1]]++;
    while (l<=n&&r<=n) {
        while (cnt<m&&r<=n) {
            r++;
            c[a[r]]++;
            if (c[a[r]]==1) cnt++;
        }
        while (c[a[l]]>1) {
            c[a[l]]--;
            l++;
        }
        if (r<=n&&l<=n&&r>=l)
            res=min(res,r-l+1);
        c[a[l]]--;
        if (c[a[l]]==0) cnt--;
        l++;
    }
    cout<<res;
}
