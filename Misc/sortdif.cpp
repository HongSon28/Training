#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k,a[N+5],res;
long long bi(long long m){
    long long cnt=0;
    for(int i=1;i<n;i++){
        int l=i+1,r=n,id=i;
        while(l<=r){
            long long mid=(l+r)/2;
            if(a[mid]-a[i]<=m){
                id=mid;
                l=mid+1;
            }else r=mid-1;
        }
        cnt+=id-i;
    }
    return cnt;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=a[n]-a[1];
    while(l<=r){
        long long m=(l+r)/2;
        if(bi(m)<k){
            res=m;
            l=m+1;
        } else r=m-1;
    }
    cout<<res+1;
}