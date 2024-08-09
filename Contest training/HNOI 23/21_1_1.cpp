#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
bool p[N+5];
int c[N+5];
int t,l,r;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i<=N;i++) {
        if (p[i])
            for (long long j=i*i;j<=N;j+=i)
                p[j]=false;
    }
}
bool cnt(int k) {
    int ans=0;
    while (k>0) {
        ans+=k%10;
        k/=10;
    }
    return (ans%5==0);
}
void init() {
    for (int i=1;i<=N;i++) {
        c[i]=c[i-1];
        if (p[i]&&cnt(i)) c[i]++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    init();
    cin>>t;
    while (t--) {
        cin>>l>>r;
        cout<<c[r]-c[l-1]<<'\n';
    }
}
