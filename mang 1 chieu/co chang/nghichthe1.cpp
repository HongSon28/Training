#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<"0 ";
    for (int i=1;i<n;i++) {
        int dem=0;
        for (int j=i-1;j>=0;j--) {
            if (a[i]<a[j])
                dem++;
        }
        cout<<dem<<" ";
    }
}
