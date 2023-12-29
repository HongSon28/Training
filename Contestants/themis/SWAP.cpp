#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+5],b[N+5];
int pos[N+5];
int calc1(int r) {
    int ans=0;
    vector<int>v;
    v.push_back(0);
    for (int i=1;i<=r;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    for (int i=1;i<=r;i++) {
        int p=pos[v[i]];
        while (p<i) {
            swap(pos[a[p]],pos[a[p+1]]);
            swap(a[p],a[p+1]);
            p++;
            ans++;
        }
        while (p>i) {
            swap(pos[a[p]],pos[a[p-1]]);
            swap(a[p],a[p-1]);
            p--;
            ans++;
        }
    }
    return ans;
}
int calc2(int l) {
    int ans=0;
    vector<int>v;
    v.push_back(n+1);
    for (int i=l;i<=n;i++) v.push_back(a[i]);
    sort(v.rbegin(),v.rend());
    for (int i=1;i<(int)v.size();i++) {
        int p=pos[v[i]];
        while (p<i+l-1) {
            swap(pos[a[p]],pos[a[p+1]]);
            swap(a[p],a[p+1]);
            p++;
            ans++;
        }
        while (p>i+l-1) {
            swap(pos[a[p]],pos[a[p-1]]);
            swap(a[p],a[p-1]);
            p--;
            ans++;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SWAP.INP","r",stdin);
    freopen("SWAP.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) a[i]=b[i];
        int res=0;
        for (int i=1;i<=n;i++) pos[a[i]]=i;
        int p=pos[n];
        while (p<k) {
            swap(pos[a[p]],pos[a[p+1]]);
            swap(a[p],a[p+1]);
            p++;
            res++;
        }
        while (p>k) {
            swap(pos[a[p]],pos[a[p-1]]);
            swap(a[p],a[p-1]);
            p--;
            res++;
        }
        res+=calc1(k-1)+calc2(k+1);
        cout<<res<<' ';
    }
}
