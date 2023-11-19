#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t;
int n;
int a[N+5];
int main() {
    cin>>t;
    while(t--) {
        bool flag=false;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                for (int k=1;k<=n;k++) {
                    if (i!=j&&j!=k&&i!=k) {
                        if (a[i]+a[j]==a[k]) {
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
