#include<bits/stdc++.h>
using namespace std;
int t;
int k;
int m,n;
int main() {
    freopen("CHOCO.INP","r",stdin);
    freopen("CHOCO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>k;
        if (k==1) {
            cin>>m>>n;
            if (m==1&&n==1) cout<<"NAM"<<'\n';
            else cout<<"DUY"<<'\n';
        } else {
            int c1=0,c2=0;
            for (int i=1;i<=k;i++) {
                cin>>m>>n;
                if (n==1) c1++;
                else if (n==2) c2++;
            }
            if (c1==k) cout<<"NAM"<<'\n';
            else if (c2==k) {
                if (k%2==0) cout<<"NAM"<<'\n';
                else cout<<"DUY"<<'\n';
            } else cout<<"NAM"<<'\n';
        }
    }
}
