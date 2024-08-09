#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long sum;
long long a[N+5];
long long cnt[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++) sum+=cnt[i]*(cnt[i]-1)/2;
    for (int i=1;i<=n;i++) cout<<sum-cnt[a[i]]+1<<'\n';
}
