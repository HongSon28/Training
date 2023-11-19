#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
const int maxN=1e5;
int n;
long long l,r;
long long w[N+5];
bool dp[maxN+5];
int trace[maxN+5];
pair<long long,int>pr[N+5];
long long sumleft=0,sumright=0,presum[N+5]={};
void solve1() {
    for (int mask=0;mask<(1<<n);mask++) {
        long long sum=0;
        for (int j=0;j<n;j++) {
            if ((mask>>j)&1) sum+=w[j+1];
        }
        if (sum>=l&&sum<=r) {
            int cnt=0;
            for (int j=0;j<n;j++) if ((mask>>j)&1) cnt++;
            cout<<cnt<<endl;
            for (int j=0;j<n;j++) if ((mask>>j)&1) cout<<j+1<<' ';
            return;
        }
    }
    cout<<-1;
}
void solve2() {
    int m=n/2;
    vector<pair<long long,long long>>v1;
    for (long long mask=0;mask<(1<<m);mask++)  {
        long long sum=0;
        for (int j=0;j<m;j++) {
            if ((mask>>j)&1) sum+=w[j+1];
        }
        if (sum>=l&&sum<=r) {
            int cnt=0;
            for (int j=0;j<n;j++) if ((mask>>j)&1) cnt++;
            cout<<cnt<<endl;
            for (int j=0;j<n;j++) if ((mask>>j)&1) cout<<j+1<<' ';
            return;
        }
        v1.push_back({sum,mask});
    }
    sort(v1.begin(),v1.end());
    int len=n-m;
    for (long long mask=0;mask<(1<<len);mask++) {
        long long sum=0;
        for (int j=0;j<len;j++) {
            if ((mask>>j)&1) sum+=w[j+1+m];
        }
        if (sum>=l&&sum<=r) {
            int cnt=0;
            for (int j=0;j<len;j++) if ((mask>>j)&1) cnt++;
            cout<<cnt<<endl;
            for (int j=0;j<len;j++) if ((mask>>j)&1) cout<<j+1+m<<' ';
            return;
        }
        pair<long long,long long>pp={l-sum,0};
        auto it=lower_bound(v1.begin(),v1.end(),pp);
        if (it==v1.end()) continue;
        pair<long long,long long>temp=*it;
        if (temp.first+sum<=r&&temp.first+sum>=l) {
            vector<int>tr;
            for (int j=0;j<len;j++) if ((mask>>j)&1) tr.push_back(j+1+m);
            for (int j=0;j<m;j++) if ((temp.second>>j)&1) tr.push_back(j+1);
            cout<<tr.size()<<endl;
            sort(tr.begin(),tr.end());
            for (auto k:tr) cout<<k<<' ';
            return;
        }
    }
    cout<<-1;
}
void solve3() {
    vector<int>tr;
    dp[0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=r;j>=w[i];j--) {
            if (dp[j-w[i]]&&!dp[j]) {
                dp[j]=true;
                trace[j]=i;
            }
            if (dp[j]&&j>=l&&j<=r) {
                int val=j;
                while (val>0) {
                    int temp=trace[val];
                    val-=w[temp];
                    tr.push_back(temp);
                }
                cout<<tr.size()<<endl;
                sort(tr.begin(),tr.end());
                for (auto k:tr) cout<<k<<' ';
                return;
            }
        }
    }
    cout<<-1;
}
void solve5() {
    vector<int>tr;
    pair<long long,int>p[N+5];
    for (int i=1;i<=n;i++) {
        p[i].first=w[i];
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    long long sum=0;
    for (int i=n;i>=1;i--) {
        sum+=p[i].first;
        if (sum>r) sum-=p[i].first;
        else tr.push_back(i);
        if (sum>=l&&sum<=r) {
            cout<<tr.size()<<endl;
            sort(tr.begin(),tr.end());
            for (auto k:tr) cout<<k<<' ';
            return;
        }
    }
}
void solve6() {
    vector<int>tr;
    int k=1;
    for (int i=1;i<=n;i++) {
        pr[i].first=w[i];
        pr[i].second=i;
    }
    sort(pr+1,pr+1+n);
    for (int i=1;i<=n;i++) presum[i]=presum[i-1]+pr[i].first;
    while (sumleft>r||sumright<l) {
        sumleft+=pr[k].first;
        sumright+=pr[n-k+1].first;
        k++;
        if (k>n) break;
    }
    k--;
    for (int i=1;i<=n-k+1;i++) {
        int j=i+k-1;
        if (presum[j]-presum[i-1]>=l&&presum[j]-presum[i-1]<=r) {
            for (int t=i;t<=j;t++) tr.push_back(pr[t].second);
            cout<<tr.size()<<endl;
            sort(tr.begin(),tr.end());
            for (auto k:tr) cout<<k<<' ';
            return;
        }
    }
    cout<<-1;
}
int main() {
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) cin>>w[i];
    if (n<=20) solve1();
    else if (n<=40) solve2();
    else if (n<=80) solve3();
    else {
        int cnt1=1,cnt2=1;
        for (int i=1;i<n;i++) {
            if (w[i]==w[i+1]) cnt1++;
            if (w[i]==i) cnt2++;
        }
        if (cnt1==n) solve6();
        else if (cnt2==n) solve5();
        else solve6();
    }
}
