#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int cnt=0;
    for (int i=0;i<n;i++) {
        if (s>=a[i]) {
            s+=a[i];
            cnt++;
        } else break;
    }
    cout<<cnt;
}
