#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
long long a[N+5];
long long res=-1e18;
long long sum;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        sum+=a[i];
        res=max(res,sum);
        if (sum<0) sum=0;
    }
    cout<<res;
}
