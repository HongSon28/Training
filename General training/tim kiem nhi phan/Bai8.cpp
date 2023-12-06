#include<bits/stdc++.h>
using namespace std;
int u[100000];
int a[100000];
int dem=1;
bool check(int b) {
    int lo=0, hi=dem-1;
    while(hi>=lo) {
        int mid=lo+(hi-lo)/2;
        if (b>u[mid]) {
            lo=mid+1;
        } else if (b<u[mid]) {
            hi=mid-1;
        } else {
            return true;
        }
    }
    return false;
}
bool checknt(int b) {
    for (int i=2;i<=sqrt(b);i++) {
        if (b%i==0)
            return false;
    }
    return true;
}
int main() {
    int n,x,y;
    cin>>n>>x>>y;
    int mx=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    u[0]=x;
    while (u[dem-1]<mx) {
        u[dem]=u[dem-1]+y;
        dem++;
    }
    int demnt=0;
    for (int i=0;i<n;i++) {
        if (check(a[i])==true) {
            if (checknt(a[i])==true)
                demnt++;
        }
    }
    cout<<demnt;
}
