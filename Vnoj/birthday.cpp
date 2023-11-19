#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,t;
pair<int,int>p[N+5];
int res;
int main() {
    cin>>n>>t;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for (int i=1;i<=n;i++) {
        int cost=p[i].first-p[i-1].first;
        if (cost<=t) {
            t-=cost+p[i].second;
            res++;
        } else break;
    }
    cout<<res;
}
