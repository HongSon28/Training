#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N+5];
long long mx[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a[1]=1;
    mx[1]=1;
    for (int i=2;i<=N;i++) {
        if (i%2==0) a[i]=a[i/2];
        else a[i]=a[i/2]+a[i/2+1];
        mx[i]=max(mx[i-1],a[i]);
    }
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cout<<mx[n]<<endl;
    }
}
