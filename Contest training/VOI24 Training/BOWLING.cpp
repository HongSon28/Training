#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,r;
long long inf=1e18,a[N+5],sum[N+5],f[N+5],g[N+5],res=-inf,h[N+5];
deque<long long>Q;
void Update(int i)
{
    if (f[i]==inf) g[i]=inf;
    else g[i] = f[i]-sum[i];
    if (i>0) g[i]=min(g[i], g[i-1]);
    while (!Q.empty()&&f[Q.back()]>=f[i]) Q.pop_back();
    Q.push_back(i);
    if (Q.front()+r<=i) Q.pop_front();
    h[i]=f[Q.front()];
}
int main() {
	freopen("BOWLING.INP","r",stdin);
	freopen("BOWLING.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>r;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n+r;i++) sum[i]=sum[i-1]+a[i];
    if (n==1) {
    	cout<<a[1];
    	return 0;
    }
    Update(0);
    for (int i = 1; i <= r; ++i) {
        f[i]=inf;
        Update(i);
    }
    for (int i=r+1;i<=n+r;i++)
    {
        long long fval1=(i<=2*r+1)?0:g[i-2*r-1]+sum[i-2*r-1];
        long long fval2=h[i-r-1];
        f[i] = min(fval1, fval2);
        Update(i);
        res=max(res,sum[i]-f[i]);
    }
    cout<<res;
}