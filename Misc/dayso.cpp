#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5;
const int inf=1e9;
int n,q,b[N+5],c[N+5];
pair<int,int>a[N+5];
stack<int>st;
bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.fi==b.fi) return a.se<b.se;
    return a.fi<b.fi;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].fi;
    a[0].fi=a[n+1].fi=inf;
    st.push(0);
    for(int i=1;i<=n;i++){
        int x=a[i].fi;
        while (a[st.top()].fi<=x) st.pop();
        b[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i=n;i>=1;i--){
        int x=a[i].fi;
        while (a[st.top()].fi<=x) st.pop();
        c[i]=st.top()-1;
        st.push(i);
    }
    for(int i=1;i<=n;i++) a[i].se=c[i]-b[i]+1;
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++) a[i].se=max(a[i].se,a[i-1].se);
    while(q--){
        int k; cin>>k;
        int l=1,r=n,p=0;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m].fi<k){
                p=m;
                l=m+1;
            }else r=m-1;
        }
        cout<<a[p].se<<'\n';
    }
}