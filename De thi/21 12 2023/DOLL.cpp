#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+10],dp[N+10];
set<int>s;
vector<int>cur;
bool sub2=true,sub3=true;
int lis(int t) {
    for (int i=1;i<=t;i++) {
        dp[i]=1;
        for (int j=i-1;j>=0;j--) {
            if (a[i]-a[j]>=2) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    return dp[t];
}
void solve1() {
    for (int i=1;i<=n;i++) {
        sort(a+1,a+1+i);
        cout<<lis(i)<<' ';
    }
}
void solve2() {
    for (int i=1;i<=n;i++) {
        s.insert(a[i]);
        cout<<s.size()<<' ';
    }
}
bool used[N+5];
void solve3() {
    int res=0;
    for (int i=1;i<=n;i++) {
        if (used[a[i]]) {
            cout<<res<<' ';
            continue;
        }
        used[a[i]]=true;
        if (a[i]%4==1) {
            if (!used[a[i]+1]) res++;
            else if (used[a[i]+2]) res++;
        } else if (a[i]%4==2) {
            if (!used[a[i]+1]&&!used[a[i]-1]) res++;
        } else {
            if (!used[a[i]-1]) res++;
            else if (used[a[i]-2]) res++;
        }
        cout<<res<<' ';
    }
}
int main() {
    freopen("DOLL.INP","r",stdin);
    freopen("DOLL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=4;
        if (a[i]%2==0) sub2=false;
        if (a[i]%4==0) sub3=false;
    }
    if (sub2) solve2();
    else if (sub3) solve3();
    else solve1();
}
