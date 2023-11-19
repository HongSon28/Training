#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,w;
double inf=1e9+5;
pair<int,int> a[N+5];
vector<double>b(N+1,inf);
int res;
int main() {
    //freopen("FRACTION.INP","r",stdin);
    //freopen("FRACTION.OUT","w",stdout);
    cin>>n>>w;
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    b[0]=-inf;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),(double)a[i].first/(double)a[i].second)-b.begin();
        b[k]=(double)a[i].first/(double)a[i].second;
        res=max(res,k);
        if (w==1) {
            int k=lower_bound(b.begin(),b.end(),(double)a[i].second/(double)a[i].first)-b.begin();
            b[k]=(double)a[i].second/(double)a[i].first;
            res=max(res,k);
        }
    }
    cout<<res;
    //for (int i=1;i<=res;i++) cout<<p[i]<<' ';
}

