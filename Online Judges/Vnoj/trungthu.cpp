#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    int a[n];
    int sum=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    m-=sum;
    sort (a,a+n);
    while (m>=a[0]) {
        m-=a[0];
        n++;
    }
    cout<<n;
}
