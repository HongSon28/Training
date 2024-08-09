#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,x,cnt;
bool p[N+5];
int a[N+5];
int c[N+5];
int res;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i<=N;i++)
        if (p[i])
            for (int j=i*2;j<=N;j+=i) p[j]=false;
}
int main() {
    seive();
    cin>>n>>x;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[i]=c[i-1];
        if (a[i]>0&&a[i]<=x&&p[a[i]]) {
            cnt++;
            c[i]++;
        }
    }
    for (int r=cnt;r<=n;r++) {
        int l=r-cnt+1;
        res=max(res,c[r]-c[l-1]);
    }
    cout<<cnt-res;
}
