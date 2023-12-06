#include<bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin>>t;
    long long dem=0;
    string a[dem+1];
    for (int i=2;i<=t;i++) {
        while (t%i==0) {
            a[dem]=to_string(i);
            t/=i;
            dem++;
            cout<<i<<" "<<dem<<endl;
        }
    }
    if (dem==0) {
        a[dem]=to_string(t);
        dem++;
    }
    for (int b=0;b<dem-1;b++) {
        for (int c=b+1;c<dem;c++) {
            if (a[c]+a[b]>a[b]+a[c])
                swap(a[b],a[c]);
        }
    }
    for (int j=0;j<dem;j++) {
        cout<<a[j];
    }
}

