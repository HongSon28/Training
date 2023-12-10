#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    unsigned int dem=0;
    cin>>n;
    unsigned int m=n*2;
    long long a[m];
    for (int i=0;i<m;i++) {
        cin>>a[i];
    }
    for (int j=0;j<m;j=j+2) {
        if (a[j+1]*2>a[j]) {
            cout<<"-1"<<endl;
        } else if (a[j+1]*2==a[j]) {
            cout<<"0"<<endl;
        } else {
            dem=0;
            while (a[j+1]*2!=a[j]) {
                dem=dem+1;
                a[j+1]=a[j+1]+1;
                a[j]=a[j]+1;
            }
            cout<<dem<<endl;
        }
    }
}

