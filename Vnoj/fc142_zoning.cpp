#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e6;
int n;
long long x;
long long a[N+5];
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>x;
        for (int i=1;i<=n;i++) cin>>a[i];
        long long l=1,r=1,sum=a[1],res=0;
        while(l<=n&&r<=n) {
            if (sum<x) {
                r++;
                sum+=a[r];
            } else if (sum>x) {
                sum-=a[l];
                l++;
            } else {
                res++;
                sum-=a[l];
                l++;
                r++;
                sum+=a[r];
            }
        }
        if (res==0) cout<<"HUHU"<<endl;
        else cout<<res<<endl;
    }
}
