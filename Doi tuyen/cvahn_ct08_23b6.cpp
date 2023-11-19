#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
string s[N+5];
int res;
int main() {
    freopen("BIENDOIXAU.INP","r",stdin);
    freopen("BIENDOIXAU.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]=' '+s[i];
    }
    cin>>s[0];
    int d=s[0].size();
    s[0]=' '+s[0];
    for (int i=1;i<=d;i++) {
        bool flag=false;
        for (int j=1;j<=n;j++) {
            if (s[0][i]==s[j][i]) flag=true;
        }
        if (!flag) {
            cout<<-1;
            return 0;
        }
    }
    for (int i=1;i<=n;i++) {
        int cnt=0;
        for (int j=1;j<=d;j++) {
            if (s[i][j]==s[0][j]) cnt++;
        }
        res=max(res,cnt);
    }
    cout<<d-res;
}
