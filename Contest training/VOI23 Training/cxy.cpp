#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
map<long long,bool>vis;
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
map<long long,long long>tr;
void solve2() {
    lim=pow(10,k);
    q.push(x);
    vis[x]=true;
    while (!q.empty()) {
        long long t=q.front();
        if (t==y) {
            while (t!=x) {
                res.push_back(t);
                t=tr[t];
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
                tr[t+1]=t;
            }
        }
        long long t2=change(t);
        if (t2<=lim&&!vis[t2]) {
            q.push(t2);
            vis[t2]=true;
            tr[t2]=t;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>x>>y;
    if (k<=6) solve1();
    else solve2();
}
