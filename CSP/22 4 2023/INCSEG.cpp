#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt=1,res=1;;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n-1;i++) {
        if (a[i]<=a[i+1]) {
            cnt++;
        } else {
            res=max(res,cnt);
            cnt=1;
        }
    }
    res=max(res,cnt);
    cout<<res;
}
