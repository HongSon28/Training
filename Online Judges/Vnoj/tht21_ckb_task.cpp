#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,mx;
int a[N+5];
bool check(int p) {
    int cnt=0,cur;
    for (int i=0;i<n-1;i++) {
        cur=a[i];
        while (a[i+1]-cur>p) {
            cnt++;
            cur+=p;
        }
    }
    if (cnt>m-n) return false;
    return true;
}
int main() {
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n>m) {
        map<int,int>mp;
        for (int i=0;i<m-1;i++) {
            mp[a[i+1]-a[i]]++;
        }
        auto it=mp.rbegin();
        int res=it->first;
        for (int i=0;i<n-m;i++) {
            mp[a[i+1]-a[i]]--;
            mp[a[i+m]-a[i+m-1]]++;
            for (auto j=mp.rbegin();j!=mp.rend();j++) {
                if (j->second>0) {
                   // cout<<j->first<<endl;
                    res=min(res,j->first);
                    break;
                }
            }
        }
        cout<<res;
    } else if (n<m) {
        for (int i=0;i<n-1;i++) mx=max(mx,a[i+1]-a[i]);
        int lo=0,hi=mx;
        int res=hi;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            //cout<<lo<<' '<<hi<<' '<<mid<<endl;
            if (check(mid)==true) {
                res=min(res,mid);
                hi=mid-1;
            } else {
                lo=mid+1;
            }
        }
        cout<<res;
    }
}
