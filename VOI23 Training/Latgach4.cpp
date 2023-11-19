#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m;
set<long long>s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n>>m;
        s.clear();
        long long x=n-1,y=m-1;
        for (long long i=1;i*i<=x;i++) {
            if (x%i!=0) continue;
            long long j=x/i;
            if (y%i==0) s.insert(i);
            if (y%j==0) s.insert(j);
        }
        x=n-2,y=m;
        for (long long i=1;i*i<=x;i++) {
            if (x%i!=0) continue;
            long long j=x/i;
            if (y%i==0) s.insert(i);
            if (y%j==0) s.insert(j);
        }
        x=n,y=m-2;
        for (long long i=1;i*i<=x;i++) {
            if (x%i!=0) continue;
            long long j=x/i;
            if (y%i==0) s.insert(i);
            if (y%j==0) s.insert(j);
        }
        x=n,y=m-1;
        int z=n-2;
        for (long long i=1;i*i<=x;i++) {
            if (x%i!=0) continue;
            long long j=x/i;
            if (y%i==0&&z%i==0) s.insert(i);
            if (y%j==0&&z%j==0) s.insert(j);
        }
        x=m,y=n-1;
        z=m-2;
        for (long long i=1;i*i<=x;i++) {
            if (x%i!=0) continue;
            long long j=x/i;
            if (y%i==0&&z%i==0) s.insert(i);
            if (y%j==0&&z%j==0) s.insert(j);
        }
        cout<<s.size()<<' ';
        for (auto i:s) cout<<i<<' ';
        cout<<'\n';
    }
}
