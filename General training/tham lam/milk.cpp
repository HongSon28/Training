#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<int>());
    int mn=0,res=0;
    for (int i=0;i<n;i++) {
        if (a[i]-mn>0) res+=a[i]-mn;
        mn++;
    }
    cout<<res;
}
