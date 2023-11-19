#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5],b[N+5];
long long res=1e18;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int l=1,r=n;
    while (l<=n&&r>=1) {
        res=min(res,abs(a[l]+b[r]));
        if (a[l]+b[r]>0) r--;
        else l++;
    }
    cout<<res;
}
