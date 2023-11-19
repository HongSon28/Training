#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int cnt,res,len;
int mp[N+5];
vector<int>cprs;
int main() {
    freopen("TWOVALS.INP","r",stdin);
    freopen("TWOVALS.OUT","w",stdout);
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
    int l=1,r=2;
    mp[a[1]]++;
    cnt=res=len=1;
    while (l<=n&&r<=n) {
        mp[a[r]]++;
        len++;
        if (mp[a[r]]==1) cnt++;
        while (cnt>2) {
            mp[a[l]]--;
            if (mp[a[l]]==0) cnt--;
            len--;
            l++;
        }
        res=max(res,len);
        r++;
    }
    cout<<res;
}
