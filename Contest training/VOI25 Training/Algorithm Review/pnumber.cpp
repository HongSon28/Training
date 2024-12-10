#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int p[N+5];
int a,b;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i*i<=N;i++)
        if (p[i])
            for (int j=i*i;j<=N;j+=i)
                p[j]=false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>a>>b;
    for (int i=a;i<=b;i++) if (p[i]) cout<<i<<'\n';
}
