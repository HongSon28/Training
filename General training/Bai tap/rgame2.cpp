#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,s,k;
    cin>>n>>s>>k;
    bool a[n+1];
    memset(a,true,sizeof(a));
    int c=0,m=n,res;
    for (int i=1;m>1;i=i%n+1) {
        if (a[i]) c++;
        if (c==s) {
            m--;
            c=0;
            a[i]=false;
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]) {
            res=i;
            cout<<i<<endl;
            break;
        }
    if (res<=k) cout<<k-res+1;
    else cout<<n-res+k+1;
}
