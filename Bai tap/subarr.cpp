#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
int n;
vector<int>v1,v2;
ll res;
ll a[N+5],sum=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    ll t=0;
    for (int i=1;i<=n;i++) {
        t+=a[i];
        if (t*3==sum) v1.push_back(i);
    }
    t=0;
    for (int i=n;i>=1;i--) {
        t+=a[i];
        if (t*3==sum) v2.push_back(i);
    }
    sort(v2.begin(),v2.end());
    for (int i=0;i<v1.size();i++) {
        int lo=0,hi=v2.size()-1;
        while (lo<hi) {
            int mid=(lo+hi)/2;
            if (v1[i]+1<v2[mid]) hi=mid;
            else lo=mid+1;
        }
        if (lo==v2.size()-1) {
            if (v1[i]+1<v2[lo]) res++;
        } else res+=v2.size()-lo;
    }
    cout<<res;
}
