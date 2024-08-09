#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int res;
int n;
double x[N+5];
double ep=1e-10;
int bs1(int lo,int hi,double k) {
    int ans=0;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (k>x[mid]&&k-x[mid]>ep) {
            lo=mid+1;
        } else if (k<x[mid]&&x[mid]-k>ep){
            hi=mid-1;
        } else {
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}
int bs2(int lo,int hi,double k) {
    int ans=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (k>x[mid]&&k-x[mid]>ep) {
            lo=mid+1;
        } else if (k<x[mid]&&x[mid]-k>ep){
            hi=mid-1;
        } else {
            ans=mid;
            lo=mid+1;
        }
    }
    return ans;
}
int main() {
    freopen("CHIADEU.INP","r",stdin);
    freopen("CHIADEU.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+1+n);
    for (int i=1;i<=n;i++) {
        for (int j=i+2;j<=n;j++) {
            double md=(x[i]+x[j])/2;
            res+=bs2(i+1,j-1,md)-bs1(i+1,j-1,md)+1;
            //cout<<x[i]<<' '<<x[j]<<' '<<' '<<bs1(i+1,j-1,md)<<' '<<bs2(i+1,j-1,md)<<res<<endl;
        }
    }
    cout<<res;
}
