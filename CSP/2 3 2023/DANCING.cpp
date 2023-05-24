#include<bits/stdc++.h>
using namespace std;
long long res;
int main() {
    int n;
    cin>>n;
    long long a[n],b[n];
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    sort(b,b+n);
    sort(a,a+n);
    map<long long,long long>mp;
    for (int i=0;i<n;i++) {
        mp[b[i]+1]=i+1;
    }
    for (int i=0;i<n;i++) {
        auto it=mp.upper_bound(a[i]);
        it--;
        cout<<(*it).second<<endl;
    }
}
