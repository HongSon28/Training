#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
pair<int,int>p[N+5];
int dp1[N+5],dp2[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    dp1[1]=p[1].first;
    dp2[1]=p[1].second;
    for (int i=2;i<=n;i++) {
        dp1[i]=max(dp1[i-1]+p[i].first+abs(p[i].second-p[i-1].second),dp2[i-1]+p[i].first+abs(p[i].second-p[i-1].first));
        dp2[i]=max(dp1[i-1]+p[i].second+abs(p[i].first-p[i-1].second),dp2[i-1]+p[i].second+abs(p[i].first-p[i-1].first));
    }
    cout<<max(dp1[n],dp2[n]);
}
