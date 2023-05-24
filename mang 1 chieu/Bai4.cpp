#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    int dem=0;
    cin>>n;
    int a[64];
    while (n!=0) {
        a[dem]=n%2;
        dem+=1;
        n/=2;
    }
    for (int i=dem-1;i>=0;i--)
        cout<<a[i];
}
