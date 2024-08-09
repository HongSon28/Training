#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int n,k;
        cin>>n>>k;
        int a[n];
        for (int j=0;j<n;j++) cin>>a[j];
        int mx=*max_element(a,a+n);
        for (int j=0;j<n;j++) k-=mx-a[j];
        if (k>=0&&k%n==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
