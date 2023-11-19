#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5];
long long t;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int rem=n-i;
        a[i]+=t;
        if (rem==0) {
            cout<<a[i];
            continue;
        }
        cout<<a[i]%rem<<' ';
        t+=a[i]/rem;
    }
}
