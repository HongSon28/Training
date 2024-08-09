#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n;
bool vis[(1<<(N+2))+5];
queue<pair<int,int>>q;
bool check(int bit) {
    int cnt=0;
    for (int i=2;i<=n;i++) {
        int b1=(bit>>(i-1))&1;
        int b2=(bit>>i)&1;
        if (b1!=b2) cnt++;
    }
    if (cnt>2) return false;
    return true;
}
int main() {
    cin>>n;
    int bit=0;
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        if (t==1) bit|=(1<<i);
    }
    vis[bit]=true;
    q.push({bit,0});
    while (!q.empty()) {
        pair<int,int> t=q.front();
        q.pop();
        if (check(t.first)){
            cout<<t.second;
            return 0;
        }
        for (int i=2;i<n;i++){
            int temp=t.first;
            int b1=(temp>>(i-1))&1;
            int b2=(temp>>(i+1))&1;
            if (b1==0) temp&=~(1<<(i+1));
            else temp|=(1<<(i+1));
            if (b2==0) temp&=~(1<<(i-1));
            else temp|=(1<<(i-1));
            if (!vis[temp]) {
                vis[temp]=true;
                q.push({temp,t.second+1});
            }
        }
        int temp=t.first;
        int b1=(temp>>(n))&1;
        int b2=(temp>>(2))&1;
        if (b1==0) temp&=~(1<<2);
        else temp|=(1<<2);
        if (b2==0) temp&=~(1<<n);
        else temp|=(1<<n);
        if (!vis[temp]) {
            vis[temp]=true;
            q.push({temp,t.second+1});
        }
        temp=t.first;
        b1=(temp>>(n-1))&1;
        b2=(temp>>(1))&1;
        if (b1==0) temp&=~(1<<1);
        else temp|=(1<<1);
        if (b2==0) temp&=~(1<<(n-1));
        else temp|=(1<<(n-1));
        if (!vis[temp]) {
            vis[temp]=true;
            q.push({temp,t.second+1});
        }
    }
    cout<<-1;
}

