#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,q,len;
string s,t,t2;
char c[N+5][N+5];
bool check1(int i,int j) {
    t="";
    for (int k=j;k<=j+len-1;k++) t+=c[i][k];
    t2=t;
    reverse(t2.begin(),t2.end());
    return (s==t||s==t2);
}
bool check2(int i,int j) {
    t="";
    for (int k=i;k<=i+len-1;k++) t+=c[k][j];
    t2=t;
    reverse(t2.begin(),t2.end());
    return (s==t||s==t2);
}
bool check3(int i,int j) {
    t="";
    for (int k=1;k<=len;k++) {
        t+=c[i][j];
        i++;
        j++;
    }
    t2=t;
    reverse(t2.begin(),t2.end());
    return (s==t||s==t2);
}
bool check4(int i,int j) {
    t="";
    for (int k=1;k<=len;k++) {
        t+=c[i][j];
        i++;
        j--;
    }
    t2=t;
    reverse(t2.begin(),t2.end());
    return (s==t||s==t2);
}
void solve() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (j+len-1<=m)
                if (check1(i,j)) {
                    cout<<"YES"<<'\n';
                    return;
                }
            if (i+len-1<=n)
                if (check2(i,j)) {
                    cout<<"YES"<<'\n';
                    return;
                }
            if (i+len-1<=n&&j+len-1<=m)
                if (check3(i,j)) {
                    cout<<"YES"<<'\n';
                    return;
                }
            if (i+len-1<=n&&j+len-1>=1)
                if (check4(i,j)) {
                    cout<<"YES"<<'\n';
                    return;
                }
        }
    }
    cout<<"NO"<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>c[i][j];
    while (q--) {
        cin>>s;
        len=s.size();
        solve();
    }
}
