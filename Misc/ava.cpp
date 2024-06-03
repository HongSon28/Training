#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,k;
double a[N+5],s[N+5],mn[N+5],l=1,r=(double)1e18,res;
bool check(double m){
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i]-m;
        mn[i]=min(mn[i-1],s[i]);
        //cout<<s[i]<<' '<<mn[i-k]<<endl;
        if(s[i]>=mn[i-k]){
            return true;
        }
    }
    return false;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    //cout<<check(11);
    //return 0;
    while(r-l>1e-4){
        memset(s,0,sizeof(s));
        double m=(l+r)/2;
        cout<<m<<' '<<check(m)<<endl;
        if(check(m)){
            res=m;
            l=m;
        }else r=m;
    }
    cout<<fixed<<setprecision(3)<<res;
}