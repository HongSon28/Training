#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,res;
long long a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (long long bit=31;bit>=0;bit--) {
        int cnt=0;
        long long pattern=res|1<<bit;
        for (int i=1;i<=n;i++) {
            if ((pattern&a[i])==pattern) cnt++;
        }
        if (cnt>=2) res|=1<<bit;
    }
    cout<<res;
}

