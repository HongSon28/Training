#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[3];
    for (int i=0;i<=2;i++) {
        a[i]=n%10;
        n/=10;
    }
    for (int i=2;i>=0;i--) {
        cout<<abs(a[i]);
    }
}
