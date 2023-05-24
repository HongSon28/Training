#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int n;
    int a[10000];
    int kq[t];
    for (int m=0;m<t;m++) {
            int dem=0;
        cin>>n;
        for (int j=0;j<n;j++) {
            cin>>a[j];
        }
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (i*a[i]>j*a[j])
                    dem+=1;
            }
        }
        kq[m]=dem;
    }
    for (int m=0;m<t;m++) {
        cout<<kq[m]<<endl;
    }
}
