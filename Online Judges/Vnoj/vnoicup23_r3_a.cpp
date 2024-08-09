#include<bits/stdc++.h>
using namespace std;
int t;
int n,a,b;
int x[101];
int main() {
    cin>>t;
    while (t--) {
        bool flag=false;
        cin>>n>>a>>b;
        for (int i=1;i<=n;i++) cin>>x[i];
        int e=x[1]+a;
        int temp;
        for (int i=1;i<=n;i++) {
            if (x[i]>e) {
                temp=i;
                break;
            }
            if (i==n) flag=true;
        }
        e=x[temp]+b;
        for (int i=temp;i<=n;i++) {
            if (x[i]>e) break;
            if (i==n) flag=true;
        }
        e=x[1]+b;
        for (int i=1;i<=n;i++) {
            if (x[i]>e) {
                temp=i;
                break;
            }
            if (i==n) flag=true;
        }
        e=x[temp]+a;
        for (int i=temp;i<=n;i++) {
            if (x[i]>e) break;
            if (i==n) flag=true;
        }
        if (!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
