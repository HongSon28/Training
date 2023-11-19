#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long bit[N+5];
long long a[N+5],res,n;
vector<long long>cprs;
long long get(long long p) {
    long long ans=0;
    while (p<=N) {
        ans+=bit[p];
        p+=(p&(-p));
    }
    return ans;
}
void update (long long p){
    while (p>0) {
        bit[p]++;
        p-=(p&(-p));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    for (int i=1;i<=n;i++){
        res+=get(a[i]+1);
        update(a[i]);
    }
    cout<<res;
}
