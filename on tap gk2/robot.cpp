#include<bits/stdc++.h>
using namespace std;
int n,res,t;
struct td{
    int x,y,index;
};
bool comp(td a, td b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
td a[101];
td last;
int dp[101];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].index=i;
    }
    sort(a+1,a+1+n,comp);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            if (a[j].x<=a[i].x&&a[j].y<=a[i].y) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if (res<dp[i]) {
            res=dp[i];
            t=i;
            last=a[i];
        }
    }
    cout<<res<<endl;
    vector<int>v;
    v.push_back(last.index);
    int cnt=1;
    int temp=res;
    while (true) {
        if (dp[t]==temp-1&&last.x>=a[t].x&&last.y>=a[t].y) {
            cnt++;
            temp--;
            v.push_back(a[t].index);
            last=a[t];
        }
        if (cnt==res) break;
        t--;
    }
    for (int i=v.size()-1;i>=0;i--) {
        cout<<v[i]<<' ';
    }
}
