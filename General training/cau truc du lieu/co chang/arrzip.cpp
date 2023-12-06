#include<bits/stdc++.h>
using namespace std;
struct dat {
    int val, index;
};
bool comp (dat a, dat b) {
    return a.val<b.val;
}
int main() {
    int n;
    cin>>n;
    int b[n+1];
    dat a[n+1];
    int r=1;
    for (int i=1;i<=n;i++) {
        cin>>a[i].val;
        a[i].index=i;
    }
    sort(a+1,a+1+n,comp);
    for (int i=1;i<n;i++) {
        b[a[i].index]=r;
        if (a[i].val!=a[i+1].val) r++;
    }
    b[a[n].index]=r;
    for (int i=1;i<=n;i++) cout<<b[i]<<' ';
}
