#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
long long res;
struct rec{
    long long x,y,u,v;
} a[N+5];
struct lines{
    long long x,y1,y2,val;
    bool operator < (const lines &other) const {
        return x<other.x;
    }
};
vector<lines>line,line2;
long long c[N*2+5],last[N*2+5];
void update(long long l,long long r,long long val) {
    for (int i=l;i<r;i++) c[i]+=val;
}
void calc() {
    for (int i=0;i<=2*N;i++) {
        if (c[i]==0&&last[i]>0) res++;
        if (c[i]>0&&last[i]==0) res++;
        last[i]=c[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("PIC.INP","r",stdin);
    freopen("PIC.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y>>a[i].u>>a[i].v;
        a[i].x+=N,a[i].y+=N,a[i].u+=N,a[i].v+=N;
        line.push_back({a[i].x,a[i].y,a[i].v,1});
        line.push_back({a[i].u+1,a[i].y,a[i].v,-1});
        line2.push_back({a[i].y,a[i].x,a[i].u,1});
        line2.push_back({a[i].v+1,a[i].x,a[i].u,-1});
    }
    sort(line.begin(),line.end());
    for (int i=0;i<(int)line.size();i++){
        long long y1=line[i].y1,y2=line[i].y2,val=line[i].val;
        update(y1,y2,val);
        if (i==0||i==line.size()-1||line[i].x>line[i-1].x) calc();
    }
    memset(c,0,sizeof(c));
    memset(last,0,sizeof(last));
    sort(line2.begin(),line2.end());
    for (int i=0;i<(int)line2.size();i++){
        long long y1=line2[i].y1,y2=line2[i].y2,val=line2[i].val;
        update(y1,y2,val);
        if (i==0||i==line2.size()-1||line2[i].x>line2[i-1].x) calc();
    }
    cout<<res;
}
