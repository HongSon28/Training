#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int>a[N+5];
int res[N+5];
int r;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        if (a[i].first==a[i-1].first) res[a[i].second]=res[a[i-1].second];
        else res[a[i].second]=i-1;
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}
