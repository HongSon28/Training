#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+5];
vector<int>v;
map<int,int>mp;
int tr[N+5];
int main() {
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            int j=n/i;
            if (i!=j) v.push_back(j);
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for (int i=1;i<=n;i++) {
        tr[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for (auto s:v) {
        int res=n;
        int i=1;
        while (i<=n) {
            int cnt=0;
            int u=i;
            for (int j=1;j<=s;j++) {
                //cout<<i<<' '<<mp[i]<<' '<<cnt<<endl;
                if (tr[i]<u)
                    cnt++;
                i++;
            }
            res=min(res,cnt);
        }
        cout<<s<<' '<<res<<endl;
    }
}
