#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int res=2,length=2;
    for (int i=2;i<n;i++) {
        if (a[i]==a[i-1]&&a[i-1]==a[i-2]) {
            length=2;
        } else {
            length++;
        }
        res=max(res,length);
    }
    cout<<res;
}
