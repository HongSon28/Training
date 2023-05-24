#include<bits/stdc++.h>
using namespace std;
int n,m;
int mx;
bool flag=false;
int a[105];
int p[105];
int used[105];
void rec(int s,int k) {
    //cout<<s<<' '<<k<<endl;
    if (flag) exit(0);
    for (int i=1;i<=n;i++) {
        if (!used[i]) {
            used[i]=true;
            p[k]=i;
            if (s-a[i]>0) rec(s-a[i],k+1);
            else if (s-a[i]==0&&!flag) {
                cout<<"YES"<<endl;
                sort(p+1,p+1+k);
                for (int i=1;i<=k;i++) cout<<p[i]<<' ';
                flag=true;
                exit(0);
            }
            used[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SUBSETSUM.INP","r",stdin);
    freopen("SUBSETSUM.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mx+=a[i];
    }
    if (mx<m) {
        cout<<"NO";
        return 0;
    } else if (mx==m) {
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++) cout<<i<<' ';
        return 0;
    }
    rec(m,1);
    if (!flag) cout<<"NO";
}
