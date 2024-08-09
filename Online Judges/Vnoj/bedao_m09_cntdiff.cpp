#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k;
int a[N+5];
int cnt,res;
map<int,int>mp;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) {
        if (mp[a[i]]==0) cnt++;
        mp[a[i]]++;
    }
    res=cnt;
    for (int i=k+1;i<=n;i++) {
        mp[a[i-k]]--;
        if (mp[a[i-k]]==0) cnt--;
        if (mp[a[i]]==0) cnt++;
        mp[a[i]]++;
        res=max(res,cnt);
        //cout<<i<<' '<<cnt<<endl;
    }
    cout<<res;
}
