#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N+5];
int res=INT_MAX;
int calc(int l,int r) {
    int ans=0;
    for (int i=l;i<=r;i++) {
        for (int j=i+1;j<=r;j++) {
            ans+=(a[j]<a[i]);
        }
    }
    return ans;
}
int main(){
    freopen("divinv.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<n;i++) {
        res=min(res,calc(1,i)+calc(i+1,n));
    }
    cout<<res;
}


