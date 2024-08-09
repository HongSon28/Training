#include<bits/stdc++.h>
using namespace std;
int main() {
    long long mn=INT_MAX,res=0,sum=0,cnt=0;
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mn=min(mn,a[i]);
        sum+=a[i];
        cnt++;
    }
    if (sum<=m) {
        res+=(m/sum)*cnt;
        m%=sum;
    }
    while (m>=mn) {
        for (int i=0;i<n;i++) {
            if (m<mn) break;
            if (m>=a[i]) {
                res++;
                m-=a[i];
            }
        }
    }
    cout<<res;
}
