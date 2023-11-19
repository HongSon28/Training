#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
int cnt;
int d[N+5],c[N+5];
bool used[N+5];
void seive() {
    for (int i=1;i<=N;i++) d[i]=i;
    for (int i=2;i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    freopen("RADIO.INP","r",stdin);
    freopen("RADIO.OUT","w",stdout);
    seive();
    cin>>n>>q;
    while (q--) {
        char type;
        cin>>type;
        if (type=='S') {
            int x;
            cin>>x;
            if (used[x]) {
                used[x]=false;
                while (x>1) {
                    int div=d[x];
                    while (x%div==0) x/=div;
                    c[div]--;
                    if (c[div]==1) cnt--;
                }
            } else {
                used[x]=true;
                while (x>1) {
                    int div=d[x];
                    while (x%div==0) x/=div;
                    c[div]++;
                    if (c[div]==2) cnt++;
                }
            }
        } else {
            int u,v;
            cin>>u>>v;
            if (cnt>=1) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
