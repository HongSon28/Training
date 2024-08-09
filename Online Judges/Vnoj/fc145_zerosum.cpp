#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
map<long long, long long>mp;
long long res,sum;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    mp[0]++;
    for (int i=1;i<=n;i++) {
        sum+=a[i];
        mp[sum]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) res+=(i->second)*(i->second-1)/2;
    cout<<res;
}
