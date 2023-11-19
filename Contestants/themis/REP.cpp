#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
    long long a,b,c;
    bool operator < (const dat &other) const {
        if (b==other.b) return c<other.c;
        return b<other.b;
    }
} s[N+5];
vector<dat>z;
int n;
long long res;
long long bs(int m) {
    long long l=0,r=z.size()-1,pos=z.size(),ans=0;
    while (l<=r) {
        long long mid=(l+r)/2;
        if (z[mid].b>=s[m].a) {
            pos=mid;
            r=mid-1;
        } else l=mid+1;
    }
    for (int i=pos;i<z.size();i++) {
        long long l=max(z[i].a,s[m].a);
        long long r=min(z[i].b,s[m].b);
        ans+=r-l+1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("REP.INP","r",stdin);
    freopen("REP.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].c;
    sort(s+1,s+1+n);
    for (int i=1;i<=n;i++) {
        int k=s[i].c-bs(i);
        if (k<=0) continue;
        //cout<<i<<' '<<k<<' '<<' '<<bs(i)<<' '<<s[i].c<<endl;
        z.push_back({s[i].b-k+1,s[i].b,k});
        res+=k;
    }
    cout<<res;
}
