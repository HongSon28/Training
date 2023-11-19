#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int d[N+5];
vector<int>prime;
int n,res,t,cnt;
int a[N+5];
int c[N+5];
queue<int>rev;
void seive() {
    iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    freopen("GROBOT.INP","r",stdin);
    freopen("GROBOT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;
    while (t--) {
        res=0,cnt=0;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            if (a[i]==0) cnt++;
            a[i]=abs(a[i]);
            while (a[i]>1) {
                int div=d[a[i]];
                c[div]++;
                if (c[div]==1) rev.push(div);
                while (a[i]%div==0) a[i]/=div;
                res=max(res,c[div]);
            }
        }
        while (!rev.empty()) {
            c[rev.front()]=0;
            rev.pop();
        }
        cout<<res+cnt<<'\n';
    }
}
