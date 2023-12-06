#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    int cnt=1,mx=a[0];
    for (int i=1;i<n;i++) {
        if (mx>0) {
            cnt++;
            mx--;
            mx=min(mx,a[i]);
        } else break;
    }
    cout<<cnt;
}
