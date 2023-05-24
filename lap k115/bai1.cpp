#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    cin>>n;
    long long a[n];
    long long total=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        total=total+a[i];
    }
    cout<<total;
}
