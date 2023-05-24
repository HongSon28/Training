#include <bits/stdc++.h>
using namespace std;
int l,r,k,lo,hi,mid;
bool P(int l,int r,int k) {
    for (int x=l;x<=r;x++) {
        if ((pow(x,k)>=l)&&(pow(x,k)<=r)) {
            return false;
        }
    }
    return true;
}
int binarySearch (int hi,int duoi) {
    int lo=2;
    while (lo<hi) {
        int mid=lo+(hi-lo)/2;
        if (P(duoi,mid,hi)==true) {
            hi=mid-1;
        } else {
            lo=mid;
        }
    }
    if (P(duoi,hi,mid)==true)
        return -1;
    return lo;
}
int main() {
    unsigned n;
    cin>>n;
    unsigned l[n];
    unsigned r[n];
    for (unsigned i=0;i<n;i++) {
        cin>>l[i]>>r[i];
    }
    for (unsigned i=0; i<n;i++) {
        cout<<"Case #"<<i+1<<": "<<binarySearch(r[i],l[i])<<endl;
    }
}
