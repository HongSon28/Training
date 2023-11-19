#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,k,res,sum;
struct robot{
    int u,v;
    char d;
} a[N+5];
vector<int>cprs;
vector<pair<int,char>>v[N+5],v2[N+5];
struct Node {
    long long val,lazy;
};
Node st[N*4+5];
void down(int id,int l,int r) {
    int mid=(l+r)/2;
    long long t=st[id].lazy;
    st[id].lazy=0;
    st[id*2].lazy+=t;
    st[id*2].val+=t*(mid-l+1);
    st[id*2+1].lazy+=t;
    st[id*2+1].val+=t*(r-mid);
}
void update(int id,int l,int r,int u,int v,long long val) {
    if (l>v||r<u) return;
    if (l>=u&&r<=v) {
        st[id].val+=val*(r-l+1);
        st[id].lazy+=val;
        return;
    }
    down(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
long long get(int id,int l,int r,int u,int v) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
    if (r<u||l>v) return 0;
    if (l>=u&&r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id,l,r);
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) {
        cin>>a[i].u>>a[i].v>>a[i].d;
        if (a[i].d=='W') sum+=a[i].v;
        else if (a[i].d=='E') sum+=m-a[i].v+1;
        cprs.push_back(a[i].v);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=k;i++) {
        a[i].v=lower_bound(cprs.begin(),cprs.end(),a[i].v)-cprs.begin()+1;
        v2[a[i].v].push_back({a[i].u,a[i].d});
    }
    for (int i=1;i<=N;i++) {
        int lo=N+5,hi=-1;
        for (auto p:v2[i]) {
            int row=p.first;
            char dir=p.second;
            if (dir=='S') hi=max(hi,row);
            if (dir=='N') lo=min(lo,row);
        }
        if (hi>=lo) {
            sum+=n;
        } else {
            if (hi!=-1) {
                sum+=hi;
            }
            if (lo!=N+5) {
                sum+=n-lo+1;
            }
        }
    }
    cprs.clear();
    for (int i=1;i<=k;i++) cprs.push_back(a[i].u);
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=k;i++) a[i].u=lower_bound(cprs.begin(),cprs.end(),a[i].u)-cprs.begin()+1;
    for (int i=1;i<=k;i++) v[a[i].v].push_back({a[i].u,a[i].d});
    int MX=cprs.size();
    for (int col=1;col<=MX;col++) {
        int lo=N+5,hi=-1;
        for (auto p:v[col]) {
            int row=p.first;
            char dir=p.second;
            if (dir=='S') hi=max(hi,row);
            if (dir=='N') lo=min(lo,row);
        }
        if (hi>=lo) {
            update(1,1,N,1,N,1);
        } else {
            if (hi!=-1) {
                update(1,1,N,1,hi,1);
                //cout<<"updS"<<' '<<1<<' '<<hi<<endl;
            }
            if (lo!=N+5) {
                update(1,1,N,lo,N,1);
                //cout<<"updN"<<' '<<lo<<' '<<N<<endl;
            }
        }
        for (auto p:v[col]) {
            int row=p.first;
            char dir=p.second;
            if (dir=='S'||dir=='N') continue;
            if (dir=='W') {
                res+=get(1,1,N,row,row);
                cout<<row<<' '<<get(1,1,N,row,row)<<endl;
                update(1,1,N,row,row,col);
            } else if(dir=='E'){
                res+=get(1,1,N,row,row);
                cout<<row<<' '<<get(1,1,N,row,row)<<endl;
                update(1,1,N,row,row,1);
                v[col+1].push_back({row,'F'});
            }
        }
    }
    cout<<sum-res;
}
