#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,MX=N;
struct point{
    int pos,day,last;
    bool operator < (const point &other) const {
        if (pos==other.pos) return day<other.day;
        return pos<other.pos;
    }
};
int st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
    if (l>pos||r<pos) return;
    if (l==pos&&r==pos) {
        st[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=st[id*2]+st[id*2+1];
}
int get(int id,int l,int r,int u,int v) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
    if (r<u||l>v) return 0;
    if (l>=u&&r<=v) return st[id];
    int mid=(l+r)/2;
    int get1=get(id*2,l,mid,u,v);
    int get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
}
pair<int,int>p[N+5];
int res[N+5];
vector<point>vc;
bool comp(pair<int,int>a,pair<int,int>b) {
    return a.second<b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=m;i++) {
        int t,x;
        cin>>t;
        vector<int>temp;
        while (t--) {
            cin>>x;
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end());
        int prev=0;
        for (int j=0;j<temp.size();j++) {
            vc.push_back({temp[j],i,prev});
            prev=temp[j];
        }
        vc.push_back({MX+1,i,prev});
    }
    int i=1;
    sort(vc.begin(),vc.end());
    for (auto pnt:vc) {
        //cout<<pnt.pos<<' '<<pnt.day<<' '<<pnt.last<<'\n';
        while (i<=n&&p[i].second<pnt.pos) {
            update(1,1,MX,p[i].first,1);
            i++;
        }
        res[pnt.day]+=get(1,1,MX,pnt.last+1,pnt.pos-1);
    }
    for (int i=1;i<=m;i++) cout<<n-res[i]<<'\n';
}
