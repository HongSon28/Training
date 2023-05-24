#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+2];
int c[N+2];
void sang() {
    fill(p,p+N+2,true);
    p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("CPRIME.INP","r",stdin);
    freopen("CPRIME.OUT","w",stdout);
    sang();
    for (int i=1;i<=N;i++) {
        if (p[i]==true) c[i]=c[i-1]+1;
        else c[i]=c[i-1];
    }
    int t;
    cin>>t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        cout<<c[b]-c[a-1]<<endl;
    }
}
