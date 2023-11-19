#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,b;
pair<long long,long long> p[N+5];
long long res;
int main() {
    cin>>n>>b;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
        long long temp=min(b/p[i].first,p[i].second);
        res+=temp;
        b-=temp*p[i].first;
    }
    cout<<res;
}
