#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,c;
bool p[N+5];
bool vis[N+5];
int trace[N+5];
vector<int>prime;
void seive() {
    memset(p,true,sizeof(p));
    for (long long i=2;i<=N;i++) {
        if (p[i]){
            prime.push_back(i);
            for (long long j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    seive();
    cin>>n>>m>>c;
    queue<pair<int,int>>q;
    q.push({n,0});
    vis[n]=true;
    while (!q.empty()) {
        int t=q.front().first,cnt=q.front().second;
        q.pop();
        if (t==m) {
            vector<int>tr;
            for (int i=1;i<=cnt;i++) {
                int temp=trace[t];
                if (temp==0) t=sqrt(t);
                else t*=temp;
                tr.push_back(temp);
            }
            cout<<cnt<<endl;
            reverse(tr.begin(),tr.end());
            for (auto i:tr) cout<<i<<' ';
            return 0;
        }
        for (auto pr:prime) {
            if (pr>t) break;
            if (t%pr!=0) continue;
            if (!vis[t/pr]) {
                vis[t/pr]=true;
                q.push({t/pr,cnt+1});
                trace[t/pr]=pr;
            }
        }
        if (t*t<=c) {
            if (!vis[t*t]) {
                vis[t*t]=true;
                q.push({t*t,cnt+1});
                trace[t*t]=0;
            }
        }
    }
    cout<<"Impossible";
}
