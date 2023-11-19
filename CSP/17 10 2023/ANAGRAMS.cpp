#include<bits/stdc++.h>
using namespace std;
const int N=100;
int c[N+5][N+5];
int res[N+5];
int n,k;
string a,b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("ANAGRAMS.INP","r",stdin);
    freopen("ANAGRAMS.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=k;i++) {
        cin>>a>>b;
        a=' '+a;
        b=' '+b;
        for (int x=1;x<=n;x++) {
            for (int y=1;y<=n;y++) {
                if (b[x]==a[y]) c[x][y]++;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (c[i][j]==k) {
                if (res[i]!=0) {
                    cout<<"NO SOLUTION";
                    return 0;
                }
                res[i]=j;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (res[i]==0) {
            for (int t=1;t<=n;t++) cout<<"NO SOLUTION";
            return 0;
        }
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}
