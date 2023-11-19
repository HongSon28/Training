#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
long long maxN=1e5;
int t;
long long n,k;
long long d[N+5];
void seive() {
    for (int i=1;i<=N;i++) d[i]=i;
    for (int i=2;i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (d[j]==j)
                    d[j]=i;
    }
}
pair<long long,long long> mult(pair<long long,long long>x,long long y) {
    pair<long long,long long>t,res;
    t.first=y/maxN;
    t.second=y%maxN;
    res.first=x.first*t.first*maxN+x.first*t.second+x.second*t.first+x.second*t.second/maxN;
    res.second=(x.second*t.second)%maxN;
    return res;
}
int main() {
    //freopen("PIZZA.INP","r",stdin);
    //freopen("PIZZA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;
    while (t--) {
        pair<long long,long long> res={0,1};
        cin>>n>>k;
        long long temp=k;
        while (n>1) {
            if (temp%d[n]==0) temp/=d[n];
            else res=mult(res,d[n]);
            n/=d[n];
        }
        temp=res.first*maxN+res.second;
        while (k>1) {
            int cnt=0;
            long long div=d[k];
            while (k%div==0) {
                k/=div;
                cnt++;
            }
            while (temp%div==0) {
                temp/=div;
                cnt++;
            }
            if (cnt%2!=0) res=mult(res,div);
        }
        while (temp>1) {
            int cnt=0;
            long long div=d[temp];
            while (k%div==0) {
                k/=div;
                cnt++;
            }
            while (temp%div==0) {
                temp/=div;
                cnt++;
            }
            if (cnt%2!=0) res=mult(res,div);
        }
        if (res.first==0) cout<<res.second<<'\n';
        else {
            cout<<res.first;
            if (res.second<=9) cout<<"0000";
            else if (res.second<=99) cout<<"000";
            else if (res.second<=999) cout<<"00";
            else if (res.second<=9999) cout<<"0";
            cout<<res.second<<'\n';
        }
    }
}
