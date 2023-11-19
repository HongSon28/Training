#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4;
ll n,cnt;
priority_queue<ll>pq;
pair<ll,ll>gas[N+5];
ll l,p;
bool cmp(pair<ll,ll>a,pair<ll,ll>b) {
    if (a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("EXPEDI.INP","r",stdin);
    freopen("EXPEDI.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>gas[i].first>>gas[i].second;
    sort(gas+1,gas+1+n,cmp);
    cin>>l>>p;
    gas[0].first=0;
    gas[0].second=0;
    gas[n+1].first=l;
    for (int i=n;i>=0;i--) {
        p-=gas[i+1].first-gas[i].first;
        while (p<0) {
            if (pq.size()==0) {
                cout<<-1;
                return 0;
            }
            cnt++;
            p+=pq.top();
            pq.pop();
        }
        pq.push(gas[i].second);
    }
    cout<<cnt;
}

