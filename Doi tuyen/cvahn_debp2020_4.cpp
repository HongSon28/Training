#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c[N+5],pre[N+5];
int t,l,r;
void seive() {
    for (int i=1;i<=N;i++) {
        for (int j=i;j<=N;j+=i) c[j]++;
    }
    for (int i=1;i<=N;i++) {
        pre[i]=pre[i-1];
        if (i%3==0&&c[i]==9) pre[i]++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;
    while(t--) {
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<'\n';
    }
}
