#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    unsigned int dem=0;
    unsigned int tong=0;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        dem=0;
        for (int j=1000;j<=9999;j++) {
            tong=0;
            int so=j;
            while (so != 0) {
                tong += so % 10;
                so /= 10;
        }
        if (tong==a[i]) {
            dem=dem+1;
        }
        }
        cout<<dem<<endl;
    }
}
