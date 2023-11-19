#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,l=1,r=1,cnt;
int a[N+5],c[N+5];
long long res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    c[a[1]]++;
    while (r<=n) {
        while (cnt>0) {
            c[a[l]]--;
            if (c[a[l]]==2) cnt--;
            l++;
        }
        res+=r-l+1;
        r++;
        c[a[r]]++;
        if (c[a[r]]==3) cnt++;
    }
    cout<<res;
}
