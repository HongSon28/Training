#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("NUMJOIN.INP","r",stdin);
    freopen("NUMJOIN.OUT","w",stdout);
    int n;
    cin>>n;
    string a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (a[j]+a[i]>a[i]+a[j])
                swap(a[i],a[j]);
        }
    }
    for (int i=0;i<n;i++) {
        cout<<a[i];
    }
}

