#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for (int i=2;i<=n;i++) {
        if (a[i]!=a[1]) {
            cout<<a[i]%a[1];
            return 0;
        }
    }
    cout<<0;
}
