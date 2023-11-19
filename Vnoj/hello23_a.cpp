#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t;
int n,k;
int h[N+5];
bool check(int m) {
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (h[i]>=m) cnt++;
    if (cnt>k) return false;
    return true;
}
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>h[i];
        sort(h+1,h+1+n);
        int g=-1;
        int lo=1,hi=h[n];
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (check(mid)) {
                g=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
        cout<<g<<endl;
    }
}
