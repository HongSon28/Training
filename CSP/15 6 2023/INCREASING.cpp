#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,h;
long long inf=1e18;
long long a[N+5],sum[N+5];
long long maxrange[N+5];
long long mx,s;
long long res=inf;
int main() {
    freopen("INCREASING.INP","r",stdin);
    freopen("INCREASING.OUT","w",stdout);
    cin>>n>>h;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]-=i;
        sum[i]=sum[i-1]+a[i];
    }
    deque<long long>dq;
    for (int i=1;i<=n;i++) {
        while (!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front()+h-1<i) dq.pop_front();
        if (i>=h) maxrange[i]=a[dq.front()];
    }
    for (int i=h;i<=n;i++) {
        if (maxrange[i]>mx) {
            mx--;
            s-=h;
            continue;
        }
        long long temp=sum[i]-sum[i-h];
        //cout<<i-h<<' '<<i<<' '<<temp<<' '<<s<<endl;
        res=min(res,s-temp);
        mx--;
        s-=h;
    }
    if (res==inf) cout<<-1;
    else cout<<res;
}
