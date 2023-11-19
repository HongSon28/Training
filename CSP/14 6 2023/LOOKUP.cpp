#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3;
ll n,m;
string s;
ll a[N+5],sum[N+5];
int main() {
    freopen("LOOKUP.INP","r",stdin);
    freopen("LOOKUP.OUT","w",stdout);
    cin>>n>>m;
    cin>>s;
    sum[0]=a[0]=s.size();
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
        sum[i+1]=min(sum[i+1],(ll)1e12+5);
    }
    while (m--) {
        long long k;
        cin>>k;
        if(k>sum[n]){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=n-1;i>=0;i--){
            if(k>sum[i]){
                k-=sum[i];
                k=a[i]-k+1;
            }
        }
        cout<<s[k-1]<<'\n';
    }
}
