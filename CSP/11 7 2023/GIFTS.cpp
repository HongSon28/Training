#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int m,n,res=0;
int ptr[N+5];
int c[N+5];
int a[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>m;
    for (int i=0;i<m;i++) {
        int t;
        cin>>t;
        c[t]=1;
    }
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<a[i];j++) {
            while (c[ptr[a[i]]]==2&&ptr[a[i]]<=N) {
                ptr[a[i]]+=a[i];
            }
            if (ptr[a[i]]>N) break;
            if (c[ptr[a[i]]]==1) {
                res++;
                c[ptr[a[i]]]=2;
            } else c[ptr[a[i]]]=2;
        }
    }
    cout<<res;
}

