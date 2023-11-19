#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5],temp,len,res,l[N+5],r[N+5];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SALADBAR.INP","r",stdin);
    freopen("SALADBAR.OUT","w",stdout);
    cin>>n;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=n;i++) {
        if (s[i]=='p') a[i]=1;
        else a[i]=-1;
    }
    for (int i=1;i<=n;i++) {
        temp+=a[i];
        len++;
        if (temp<0) {
            len=0;
            temp=0;
        }
        r[i]=len;
    }
    temp=len=0;
    for (int i=n;i>=1;i--) {
        temp+=a[i];
        len++;
        if (temp<0) {
            temp=0;
            len=0;
        }
        l[i]=len;
    }
    for (int i=1;i<=n;i++) {
        if (s[i]=='j') continue;
        int j=i+l[i]-1;
        if (r[j]>=l[i]) res=max(res,l[i]);
        //cout<<i<<' '<<l[i]<<' '<<r[i]<<endl;
    }
    cout<<res;
}
