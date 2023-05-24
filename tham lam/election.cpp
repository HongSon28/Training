#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    int a[n];
    if (m==1) {
        cout<<0;
        return 0;
    }
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<int>());
    for (int i=0;i<n;i++) {
        if (a[i]>m) {
            cnt++;
            m=0;
            break;
        } else {
            cnt++;
            m-=a[i]-1;
        }
    }
    if (m>0) cout<<-1;
    else cout<<cnt;
}
