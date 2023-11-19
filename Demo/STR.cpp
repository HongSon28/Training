#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,k;
int dp[N+5][N+5];
int trace[N+5][N+5];
string s[N+5];
int mx=INT_MAX;
int cost[N+5][N+5];
int calc(string x,string y) {
    int ans=0;
    string l,r;
    int j=x.size()-1;
    for (int i=0;i<x.size()-1;i++) {
        l+=y[i];
        r=x[j]+r;
        j--;
        if (l==r) ans=max(ans,i+1);
    }
    return ans;
}
bool better(string x,string y) {
    if (x.size()!=y.size()) return x.size()<y.size();
    for (int i=0;i<x.size();i++) {
        if (x[i]!=y[i]) return x[i]<y[i];
    }
}
string get(int t) {
    vector<int>tr;
    for (int i=k;i>=1;i--) {
        tr.push_back(t);
        t=trace[t][i];
    }
    reverse(tr.begin(),tr.end());
    string ans=s[tr[0]];
    int last=tr[0];
    for (int i=1;i<tr.size();i++) {
        string temp=s[tr[i]];
        temp.erase(0,cost[last][tr[i]]);
        ans+=temp;
        last=tr[i];
    }
    return ans;
}
int main() {
    //freopen("STR.INP","r",stdin);
    //freopen("STR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        dp[i][1]=s[i].size();
    }
    sort(s+1,s+1+n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cost[i][j]=calc(s[i],s[j]);
            //cout<<i<<' '<<j<<' '<<cost[i][j]<<endl;
        }
    }
    for (int i=2;i<=k;i++) {
        for (int j=1;j<=n;j++) {
            dp[j][i]=INT_MAX;
            for (int t=1;t<=n;t++) {
                int temp=dp[t][i-1]-cost[t][j]+s[j].size();
                if (dp[j][i]>temp) {
                    dp[j][i]=temp;
                    trace[j][i]=t;
                }
            }
            //cout<<i<<' '<<j<<' '<<dp[j][i]<<endl;
        }
    }
    string res;
    for (int i=1;i<=n;i++)
        if (mx>dp[i][k]) {
            mx=dp[i][k];
        }
    for (int i=1;i<=n;i++) {
        if (mx==dp[i][k]) {
            string temp=get(i);
            if (res.empty()||better(temp,res)) res=temp;
        }
    }
    cout<<res;
}
/*
5 2
ABC
ABD
BDA
DAB
CAB
*/
