// NgJaBach: Forever Meadow <3

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;
int n;
ll a[N];
namespace sub2{
    bool operator<(const vector<int>&A,const vector<int>&B){
        for(int i=0;i<(int)A.size();++i){
            if(A[i]>B[i]) return false;
            else if(A[i]<B[i]) return true;
        }
        return false;
    }
    vector<int>ans,mapping[105];
    pair<vector<int>,ll>solve(){
        int m;
        ans.clear();
        for(int k=2;k<=101;++k){
            for(int i=0;i<k;++i) mapping[i].clear();
            for(int i=1;i<=n;++i) mapping[a[i]%k].pb(i);
            for(int i=0;i<k;++i){
                if(mapping[i].empty()) continue;
                if((int)mapping[i].size()>(int)ans.size()){
                    ans=mapping[i];
                    m=k;
                }
                else if((int)mapping[i].size()==(int)ans.size() and mapping[i]<ans){
                    m=k;
                    ans=mapping[i];
                }
            }
        }
        return {ans,m};
    }
}
namespace sub3{
    vector<int>takeaway(int m,int modu){
        vector<int>res;
        for(int i=1;i<=n;++i) if(a[i]%m==modu) res.pb(i);
//        cout<<"--> "<<m<<" "<<modu<<endl;
//        for(auto tmp:res) cout<<tmp<<" "; cout<<endl;
        return res;
    }
    bool operator < (const vector<int>&A,const vector<int>&B){
        if((int)A.size()==(int)B.size()){
            for(int i=0;i<(int)A.size();++i){
                if(A[i]<B[i]) return true;
                else if(A[i]>B[i]) return false;
            }
            return false;
        }
        return (int)A.size()>(int)B.size();
    }
    vector<int>ans,vec;
    pair<vector<int>,ll>solve(){
        ll m;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                ll diff=abs(a[i]-a[j]);
                for(ll uoc=1;uoc*uoc<=diff;++uoc) if(diff%uoc==0){
                    if(uoc!=1){
                        vec=takeaway(uoc,a[i]%uoc);
                        if(vec<ans){
                            ans=vec;
                            m=uoc;
                        }
                    }
                    if(uoc!=diff/uoc){
                        vec=takeaway(diff/uoc,a[i]%(diff/uoc));
                        if(vec<ans){
                            ans=vec;
                            m=diff/uoc;
                        }
                    }
                }
            }
        }
        return {ans,m};
    }
}
pair<vector<int>,ll>ans;
vector<int>res;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(n<=50) ans=sub3::solve();
    else ans=sub2::solve();
    int m;
    tie(res,m)=ans;
    cout<<(int)res.size()<<" "<<m<<endl;
    for(const int &tmp:res) cout<<tmp<<" ";
    return 0;
}