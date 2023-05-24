#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b) {
    return a>b;
}
int main() {
    int n;
    cin>>n;
    int a[n], b[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int kq=INT_MAX;
    if (a[0]>=0&&b[0]>=0) {
        kq=a[0]+b[0];
    } else if (a[n-1]<=0&&b[n-1]<=0) {
        kq=abs(a[n-1]+b[n-1]);
    } else {
        int lo=0, hi=n-1;
        while (lo<=n-1&&hi>=0) {
            kq=min(kq,abs(a[lo]+b[hi]));
            if(kq==0)
                break;
            if (a[lo]+b[hi]<0)
                lo++;
            else
                hi--;
        }
    }
    cout<<kq;
}

