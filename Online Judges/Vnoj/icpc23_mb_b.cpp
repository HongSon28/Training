#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=2e5;
pair<long long,long long>st[N*4+5];
int k,n;
struct Segment{
    long long x,y1,y2,type;
    bool operator < (const Segment &other) const{
        if (x==other.x) return type>other.type;
        return x<other.x;
    }
};
vector<Segment>seg;
vector<long long>cprs;
long long res;
void update(int id,int l,int r,int u,int v,long long val) {
    if (u>r||l>v) return;
    if (u<=l&&r<=v) {
        st[id].second+=val;
        if (st[id].second) st[id].first=cprs[r]-cprs[l-1];
        else {
            if (l<r) st[id].first=st[id*2].first+st[id*2+1].first;
            else st[id].first=0;
        }
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    if (st[id].second) st[id].first=cprs[r]-cprs[l-1];
    else if (l!=r) st[id].first=st[id*2].first+st[id*2+1].first;
    else st[id].first=0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>n;
    long long x1=0,y1=0,x2,y2;
    seg.push_back({x1+M,y1+M,k+M,1});
    seg.push_back({k+M,y1+M,k+M,-1});
    cprs.push_back(k+M);
    cprs.push_back(k+M-1);
    for (int i=1;i<=n;i++) {
        char dir;
        long long dis;
        cin>>dir>>dis;
        x2=x1,y2=y1;
        if (dir=='E') x2=x1+dis;
        else if (dir=='W') x2=x1-dis;
        else if (dir=='N') y2=y1+dis;
        else y2=y1-dis;
        seg.push_back({min(x1,x2)+M,min(y1,y2)+M,max(y1,y2)+k+M,1});
        seg.push_back({max(x1,x2)+k+M,min(y1,y2)+M,max(y1,y2)+k+M,-1});
        //cout<<min(x1,x2)<<' '<<min(y1,y2)<<' '<<max(x1,x2)+k<<' '<<max(y1,y2)+k<<endl;
        cprs.push_back(min(y1,y2)+M);
        cprs.push_back(max(y1,y2)+k+M);
        cprs.push_back(max(y1,y2)+k-1+M);
        x1=x2;
        y1=y2;
    }
    cprs.push_back(0);
    cprs.push_back((int)1e9);
    sort(cprs.begin(),cprs.end());
    cprs.erase(unique(cprs.begin(),cprs.end()), cprs.end());
    for (int i=0;i<seg.size();i++) {
        //cout<<seg[i].x<<' '<<seg[i].y1<<' '<<seg[i].y2<<' ';
        seg[i].y1=lower_bound(cprs.begin(),cprs.end(),seg[i].y1)-cprs.begin()+1;
        seg[i].y2=lower_bound(cprs.begin(),cprs.end(),seg[i].y2)-cprs.begin()+1;
        //cout<<seg[i].y1<<' '<<seg[i].y2<<' '<<seg[i].type<<endl;
    }
    sort(seg.begin(),seg.end());
    for (int i=0;i<seg.size()-1;i++) {
        //cout<<seg[i].x<<' '<<seg[i].y1<<' '<<seg[i].y2<<' '<<seg[i].type<<endl;
        update(1,1,cprs.size(),seg[i].y1,seg[i].y2-1,seg[i].type);
        res+=(seg[i+1].x-seg[i].x)*st[1].first;
    }
    cout<<res;
}
