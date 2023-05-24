#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int j=0;j<t;j++) {
        int mx=0;
        int n,m;
        cin>>n>>m;
        int a[100000]={};
        int b[100000]={};
        for (int i=2;i<=n;i++) {
            int temp=i;
            int chia=2;
            while (temp>1) {
                if (temp%chia==0) {
                    a[chia]++;
                    temp/=chia;
                } else {
                    chia++;
                }
            }
        }
        int chia=2;
        while (m>1) {
            if (m%chia==0) {
                b[chia]++;
                m/=chia;
            } else {
                chia++;
            }
            mx=max(mx,chia);
        }
        int res=INT_MAX;
        for (int i=0;i<=mx;i++) {
            if (b[i]!=0) {
                res=min(res,a[i]/b[i]);
            }
        }
        cout<<res<<endl;
    }
}
