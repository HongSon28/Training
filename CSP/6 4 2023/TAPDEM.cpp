#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
vector<vector<int>>v(50005);
int main() {
    freopen("TAPDEM.INP","r",stdin);
    freopen("TAPDEM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    while (q--) {
        int l,r,val,cnt=0,i1,i2;
        cin>>l>>r>>val;
        if (v[val].size()==0) {
            cout<<0<<endl;
            continue;
        }
        int lo=0,hi=v[val].size()-1;
        while (lo<hi) {
            int mid=(lo+hi)/2;
            if (v[val][mid]>=l) {
                hi=mid;
            }
            else lo=mid+1;
        }
        if (v[val][lo]<l||v[val][lo]>r) {
            cout<<0<<endl;
            continue;
        } else i1=lo;
        lo=0,hi=v[val].size()-1;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (v[val][mid]<=r) {
                lo=mid;
                i2=mid;
            }
            else hi=mid-1;
        }
        if (v[val][lo]<l||v[val][lo]>r) {
            cout<<0<<endl;
            continue;
        } else i2=lo;
        cout<<i2-i1+1<<endl;
    }
}
