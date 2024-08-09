#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5];
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        int res1=0,res2=INT_MIN,res3,cnt=0,mx=INT_MIN,sum=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) {
            if (a[i]>=0) {
                res1+=a[i];
                cnt++;
            }
            mx=max(mx,a[i]);
        }
        if (cnt==0) cout<<mx<<' ';
        else cout<<res1<<' ';
        cnt=0;
        for (int i=1;i<=n;i++) {
            sum+=a[i];
            cnt++;
            if (sum<0) {
                sum=0;
                cnt=0;
            }
            if (sum>res2) {
                res2=sum;
                res3=cnt;
            }
        }
        if (res3==0) cout<<mx<<endl;
        else cout<<res2<<endl;
    }
}
