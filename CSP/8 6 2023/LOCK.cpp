#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,k;
int cnt;
int a[N+5],b[N+5];
int target[N+5];
int res=INT_MAX;
void Try(int s) {
    int t=1;
    target[0]=-1;
    for (int i=s;i<=n;i++) {
        target[t]=b[t]-a[i];
        if (target[t]<0) target[t]+=k+1;
        t++;
    }
    for (int i=1;i<s;i++) {
        target[t]=b[t]-a[i];
        if (target[t]<0) target[t]+=k+1;
        t++;
    }
    sort(target+1,target+1+n);
    //for (int i=1;i<=n;i++) cout<<target[i]<<' ';
    //cout<<endl;
    for (int i=1;i<=n;i++) {
        int sum=(n-cnt)%n+target[i];
        for (int j=1;j<=n;j++) {
            int temp=target[j]-target[i];
            if (temp<0) temp+=k+1;
            sum+=temp;
            //cout<<sum<<' ';
        }
        //cout<<endl;
        res=min(res,sum);
    }
}
int main() {
    freopen("LOCK.INP","r",stdin);
    freopen("LOCK.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) {
        Try(i);
        cnt++;
    }
    cout<<res;
}
