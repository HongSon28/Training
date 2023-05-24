#include<bits/stdc++.h>
using namespace std;
bool check(int a) {
    if (a<2)
        return false;
    for (int i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int dem=0,tong=0;
    int kq[n];
    for (int i=0;i<n;i++) {
        if (check(a[i])==true) {
            kq[dem]=a[i];
            dem++;
            tong+=a[i];
        }
    }
    cout<<tong<<endl;
    for (int i=0;i<dem;i++) {
        cout<<kq[i]<<" ";
    }
}
