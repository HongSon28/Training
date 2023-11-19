#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long res=-1e18;
long long a[N+5];
vector<long long>b,c;
int main() {
    freopen("BEAUTY.INP","r",stdin);
    freopen("BEAUTY.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n/2*2;i++) {
        if (i%2==1) b.push_back(a[i]);
        else b[b.size()-1]+=a[i];
    }
    long long left=0, right=b[0]+b[1];
    res=max(res,right);
    for (int i=2;i<b.size();i++) {
        res=max(res,right);
        right+=b[i];
        left+=b[i-2];
        if (left<0) {
            right-=left;
            left=0;
        }
        res=max(res,right);
    }
    for (int i=2;i<=n;i++) {
        if (i%2==0) c.push_back(a[i]);
        else c[c.size()-1]+=a[i];
    }
    if (n%2==0) c.pop_back();
    left=0, right=c[0]+c[1];
    res=max(res,right);
    for (int i=2;i<c.size();i++) {
        res=max(res,right);
        right+=c[i];
        left+=c[i-2];
        if (left<0) {
            right-=left;
            left=0;
        }
        res=max(res,right);
    }
    cout<<res;
}
