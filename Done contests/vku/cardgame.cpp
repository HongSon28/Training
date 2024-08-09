#include<bits/stdc++.h>
using namespace std;
long long res=INT_MIN;
int main() {
    int n,r;
    cin>>n;
    long long a[n+1],psum[n+1];
    psum[0]=0;
    long ls=0,rs=0,mx=INT_MIN;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        psum[i]=psum[i-1]+a[i];
        ls+=a[i];
        rs+=a[i];
        if (ls<0) {
            rs-=ls;
            ls=0;
        }
        //cout<<ls<<' '<<rs<<endl;
        if (mx<rs) {
            mx=rs;
            r=i;
        }
        //if (rs-ls==mx)
    }
    vector<int>v;
    for (int i=r;i>0;i--) {
        if (psum[r]-psum[i-1]==mx) {
            v.push_back(i);
        }
    }
    for (int i=0;i<v.size();i++) {
        int l=v[i];
        long long mxx=INT_MIN;
        for (int i=l;i<=r;i++) {
            mxx=max(mxx,a[i]);
        }
        res=max(res,mx-mxx);
    }
    cout<<res;
}
