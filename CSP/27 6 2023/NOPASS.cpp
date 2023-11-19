#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int res;
int a[N+5],b[N+5];
int pos1[N+5],pos2[N+5];
int mx=0;
int main() {
    freopen("NOPASS.INP","r",stdin);
    freopen("NOPASS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pos1[a[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        pos2[b[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        if (pos2[a[i]]>pos1[a[i]]) {
            if (pos2[a[i]]>mx) {
                //cout<<pos2[a[i]]<<' '<<mx<<endl;
                res+=pos2[a[i]]-mx-1;
                mx=pos2[a[i]];
            }
        }
        mx=max(mx,i);
    }
    cout<<res;
}
