#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        int dem=1,lap=0;
        for (int j=i+m;j<n+m;j+=m) {
            cout<<"j="<<j<<endl;
            if (a[j]==a[j-m]) {
                dem++;
            }
            lap++;
        }
        cout<<dem<<" "<<lap<<endl;
        if (dem==lap) {
            cout<<"YES";
            return true;
        }
    }
    cout<<"NO";
    return false;
}
