#include<bits/stdc++.h>
using namespace std;
struct bo {
    int l,r;
};
bool comp(bo a, bo b) {
    return a.r<b.r;
}
int main() {
    int k,n;
    cin>>n>>k;
    int res=1;
    bo a[10000];
    for (int i=1;i<=k;i++) {
        int t1,t2;
        cin>>t1>>t2;
        if (t1>t2)
            swap(t1,t2);
        a[i].l=t1;
        a[i].r=t2;
    }
    sort(a+1,a+k+1,comp);
    int last=a[1].r-1;
    for (int i=2;i<=k;i++) {
        if (a[i].l>last) {
            res++;
            last=a[i].r-1;
        }
    }
    cout<<res+1;
}
