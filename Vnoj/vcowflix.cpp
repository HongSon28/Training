#include<bits/stdc++.h>
using namespace std;
int main() {
    int c,n;
    cin>>c>>n;
    int a[n];
    bool f[c+1];
    memset(f,false,sizeof(f));
    f[0]=true;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) {
        for (int s=c;s>=0;s--) {
            if (s>=a[i]&&f[s-a[i]]==true) f[s]=true;
        }
    }
    int res=0;
    for (int i=0;i<=c;i++) {
        if (f[i]==true) res=max(res,i);
    }
    cout<<res;
}
