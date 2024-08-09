#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5;
int m,n;
long long a[N+5],b[N+5];
int main() {
    cin>>t;
    while (t--) {
        long long c[N+5]={};
        long long res=0;
        cin>>m>>n;
        for (int i=1;i<=m;i++) {
            cin>>a[i];
        }
        for (int i=1;i<=n;i++) {
            cin>>b[i];
        }
        for (int i=1;i<=m;i++) {
            long long cur=0;
            for (int j=1;j<=n;j++) {
                long long prev=cur;
                if (2*b[j]<=a[i]) cur=max(cur,c[j]);
                if(a[i]==b[j]) c[j]=max(c[j],prev+1);
            }
        }
        for (int i=1;i<=n;i++) {
            res=max(res,c[i]);
            //cout<<c[i]<<' ';
        }
        cout<<res<<endl;
    }
}
