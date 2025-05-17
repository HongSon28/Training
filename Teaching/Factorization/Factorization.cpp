#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e6;
int d[N+5];
void seive() {
    for (int i=1;i<=N;i++) d[i]=i;
    for (int i=2;i*i<=N;i++) {
        if (i==d[i]) {
            for (int j=i*i;j<=N;j+=i) d[j]=min(d[j],i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;
    while (t--) {
        cin>>n;
        while (n!=1) {
            int div=d[n];
            int cnt=0;
            while (n%div==0) {
                n/=div;
                cnt++;
            }
            cout<<div<<' '<<cnt<<'\n';
        }
    }
}
