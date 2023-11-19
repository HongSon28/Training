#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
pair<long long,long long>st[N*4+5];
int n;
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
    cin>>n;
    for (int i=1;i<=n;i++) {
        long long x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        seg.push_back({x1,y1,y2,1});
        seg.push_back({x2,y1,y2,-1});
        cprs.push_back(y1);
        cprs.push_back(y2);
        cprs.push_back(y2-1);
    }
    cprs.push_back(0);
    cprs.push_back((int)1e9);
    sort(cprs.begin(),cprs.end());
    cprs.erase(unique(cprs.begin(),cprs.end()), cprs.end());
    for (int i=0;i<seg.size();i++) {
        seg[i].y1=lower_bound(cprs.begin(),cprs.end(),seg[i].y1)-cprs.begin()+1;
        seg[i].y2=lower_bound(cprs.begin(),cprs.end(),seg[i].y2)-cprs.begin()+1;
        //cout<<seg[i].y1<<' '<<seg[i].y2<<endl;
    }
    sort(seg.begin(),seg.end());
    for (int i=0;i<seg.size()-1;i++) {
        //cout<<1<<' '<<cprs.size()<<' '<<seg[i].y1<<' '<<seg[i].y2<<endl;
        update(1,1,cprs.size(),seg[i].y1,seg[i].y2-1,seg[i].type);
        //cout<<seg[i].x<<' '<<seg[i+1].x<<' '<<seg[i].y1<<' '<<seg[i].y2<<endl;
        res+=(seg[i+1].x-seg[i].x)*st[1].first;
    }
    cout<<res;
}
