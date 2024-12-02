#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],b[N+5];
namespace sub1{
    bool check_sub() {
        if (n>10000) return false;
        for (int i=1;i<=n;i++) if (a[i]>2||b[i]>2) return false;
        return true;
    }
    bool check() {
        for (int i=1;i<=n;i++) if (a[i]!=b[i]) return false;
        return true;
    }
    void solve() {
        int res=0;
        while (!check()) {
            bool flag=false;
            for (int i=1;i<=n;i++) {
                if (a[i]==b[i]) continue;
                if (a[i]>b[i]) {
                    cout<<-1;
                    return;
                }
                int r=i+1,l=i-1;
                if (l==0) l=n;
                if (r==n+1) r=1;
                if (a[l]==b[i]) {
                    a[i]=a[l];
                    flag=true;
                    res++;
                } else if (a[r]==b[i]) {
                    a[i]=a[r];
                    flag=true;
                    res++;
                }
            }
            if (!flag) {
                cout<<-1;
                return;
            }
        }
        cout<<res;
    }
}
vector<int>cprs;
int main() {
    freopen("SMGAME.INP","r",stdin);
    freopen("SMGAME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cprs.push_back(a[i]);
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        cprs.push_back(b[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    int cnt=0;
    for (int i=1;i<=n;i++) {
        a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
        b[i]=lower_bound(cprs.begin(),cprs.end(),b[i])-cprs.begin()+1;
        if (a[i]==b[i]) cnt++;
    }
    if (cnt==n) {
        cout<<0;
        return 0;
    }
    if (sub1::check_sub()) sub1::solve();
    else cout<<-1;
}
/*
5
1 2 1 1 1
2 2 1 2 2
5
1 2 3 4 5
5 4 4 4 5
*/
