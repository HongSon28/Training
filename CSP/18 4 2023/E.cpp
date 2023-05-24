#include<bits/stdc++.h>
using namespace std;
const int N=2e5,M=5e5;
int n,h;
int mx=INT_MAX,cnt;
int a[N+5];
int f[M+5];
int main() {
    //freopen("E.inp","r",stdin);
    //freopen("E.out","w",stdout);
    cin>>n>>h;
    for (int i=1;i<=n;i++) {
        int l,r;
        cin>>a[i];
        if (i%2==1) l=1,r=a[i];
        else l=h-a[i]+1,r=h;
        //cout<<l<<' '<<r<<endl;
        f[l]++;
        f[r+1]--;
    }
    for(int i=1;i<=h;i++) {
        f[i]+=f[i-1];
        if(f[i]<mx) {
            mx=f[i];
            cnt=1;
        } else if (f[i]==mx) cnt++;
    }
    cout<<mx<<' '<<cnt;
}
