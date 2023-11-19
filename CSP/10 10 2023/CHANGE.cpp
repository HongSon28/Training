#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool vis[N+5];
queue<long long>q;
long long trace[N+5];
long long k,x,y,lim;
vector<long long>res;
long long cnt (long long n) {
    long long ans=0;
    while (n>0) {
        n/=10;
        ans++;
    }
    return ans;
}
long long change (long long n) {
    long long temp=pow(10,cnt(n)-1);
    long long last=n/temp;
    n%=temp;
    n=n*10+last;
    return n;
}
void solve1() {
    lim=pow(10,k);
    q.push(x);
    vis[x]=true;
    while (!q.empty()) {
        long long t=q.front();
        if (t==y) {
            while (t!=x) {
                res.push_back(t);
                t=trace[t];
            }
            cout<<res.size()<<'\n'<<x<<'\n';
            for (int i=res.size()-1;i>=0;i--) cout<<res[i]<<'\n';
            return;
        }
        q.pop();
        if (t+1<=lim) {
            if (!vis[t+1]) {
                q.push(t+1);
                vis[t+1]=true;
                trace[t+1]=t;
            }
        }
        long long t2=change(t);
        if (!vis[t2]) {
            q.push(t2);
            vis[t2]=true;
            trace[t2]=t;
        }
    }
}
map<long long,long long>tr,step;
void rec(long long cur,int cnt) {
    if (cur==y) {
        while (y!=x) {
            res.push_back(y);
            y=tr[y];
        }
        cout<<res.size()<<'\n'<<x<<'\n';
        for (int i=res.size()-1;i>=0;i--) cout<<res[i]<<'\n';
        exit(0);
    }
    if (cnt>=20) return;
    long long temp=change(cur);
    if (::cnt(cur)>1&&temp<=lim&&(step[temp]==0||step[temp]>cnt)) {
        tr[temp]=cur;
        step[temp]=cnt;
        rec(temp,cnt+1);
    }
    temp=cur+1;
    if (temp<=lim&&(step[temp]==0||step[temp]>cnt)) {
        tr[temp]=cur;
        step[temp]=cnt;
        rec(temp,cnt+1);
    }
}
void solve2() {
    lim=pow(10,k);
    rec(x,0);
}
int main() {
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>x>>y;
    if (k<=6) solve1();
    else solve2();
}
