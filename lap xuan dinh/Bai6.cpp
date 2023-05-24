#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    unsigned int dem=0;
    cin>>n;
    long long a[n];
    long long total=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        dem=0;
        for (int j=1;j<=a[i];j++) {
            if (j%3==0||j%5==0) {
                dem=dem+1;
            }
        }
        cout<<dem<<endl;
    }
}
