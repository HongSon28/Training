#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
int b[N+5];
int lo=1,hi=1e9;
int h,k;
vector<pair<int,int>>v;
bool check(int l) {
    int j=1;
    for (int i=1;i<=n;i++) {
        if (a[i]>=l) continue;
        int temp=l-a[i];
        while (b[j]<temp&&j<=m) j++;
        if (j>m) return false;
        j++;
    }
    return true;
}
int main() {
    freopen("WALL.INP","r",stdin);
    freopen("WALL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)){
            h=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    int j=1;
    for (int i=1;i<=n;i++) {
        if (a[i]>=h) continue;
        int temp=h-a[i];
        k++;
        while (b[j]<temp&&j<=m) j++;
        v.push_back(make_pair(i,j));
        j++;
    }
    cout<<h<<' '<<k<<endl;
    for (auto i:v) cout<<i.first<<' '<<i.second<<endl;
}
