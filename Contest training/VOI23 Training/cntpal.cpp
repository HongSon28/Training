#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
bool palind[N+5][N+5];
int cnt[N+5][N+5],sum[N+5][N+5];
string s;
int n,q,l,r;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;i++) palind[i][i]=true;
    for (int len=2;len<=n;len++) {
        for (int i=1;i+len-1<=n;i++) {
            int j=i+len-1;
            if (s[i]==s[j]) {
                if (len==2) palind[i][j]=true;
                else palind[i][j]=palind[i+1][j-1];
            }
        }
    }
    for (int i=1;i<=n;i++) cnt[i][i]=1;
    for (int len=2;len<=n;len++) {
        for (int i=len;i<=n;i++) {
            int j=i-len+1;
            cnt[i][j]=cnt[i][j+1]+palind[j][i];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            sum[i][j]=sum[i-1][j]+cnt[i][j];
        }
    }
    cin>>q;
    while (q--) {
        cin>>l>>r;
        cout<<sum[r][l]-sum[l-1][l]<<'\n';
    }
}
