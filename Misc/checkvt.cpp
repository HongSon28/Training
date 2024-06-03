#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int vt=0;
    for (int i=1;i<n;i++) {
        cout<<a[i]-a[vt]<<endl;
        if (a[i]-a[vt]<=k&&a[i]-a[vt]>=0) {
            vt=i;
            cout<<"vt "<<a[vt]<<endl;
        }
    }
    if (vt==n-1)
        cout<<"YES";
    else
        cout<<"NO";
}
