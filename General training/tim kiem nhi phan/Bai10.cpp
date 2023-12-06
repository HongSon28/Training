#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        float c=sqrt(a[i]);
        if (c==sqrt(a[i]))
            cout<<a[i]<<" ";
    }
}
