#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int b[N+5],r[N+5];
int res=INT_MAX;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>r[i];
    sort(b+1,b+1+n);
    sort(r+1,r+1+n);
    int i=1,j=1;
    while(i<=n&&j<=n) {
        res=min(res,abs(b[i]-r[j]));
        if (b[i]<r[j]) i++;
        else j++;
    }
    cout<<res;
}
