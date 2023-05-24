#include<bits/stdc++.h>
using namespace std;
int main() {
    string n;
    cin>>n;
    int m=n.length();
    int dem=1;
    int li,lj;
    for (int i=m-2;i>=0;i--) {
        if (n[i]>=n[i+1]) {
            dem++;
        } else {
            li=i;
            break;
        }
    }
    if (dem==m){
        cout<<"0";
        return 0;
    }
    for (int i=m-1;i>=0;i--) {
        if (n[li]<n[i]) {
            lj=i;
            break;
        }
    }
    swap(n[li],n[lj]);
    int lanlap=(m-1-li-1)/2;
    for (int i=0;i<=lanlap;i++) {
        swap(n[li+1+i],n[m-1-i]);
    }
    cout<<n;
}
