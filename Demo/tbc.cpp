#include<bits/stdc++.h>
using namespace std;
bool check(int n) {
    int tong=0;
    for (int i=1;i<=sqrt(n);i++) {
        if (n%i==0) {
            int j=n/i;
            if (j==i) {
                tong+=i;
            } else {
                tong+=i+j;
            }
        }
    }
    if (2*n<=tong)
        return true;
    return false;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    int dem=0;
    vector<int>kq;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        if (check(a[i])==true) {
            dem++;
            kq.push_back(a[i]);
        }
    }
    cout<<dem<<endl;
    for (int i=0;i<dem;i++)
        cout<<kq[i]<<endl;
}
