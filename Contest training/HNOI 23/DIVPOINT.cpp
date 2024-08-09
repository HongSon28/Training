#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
struct point {
    long long x,y;
    bool operator < (const point &other) const {
        if (x!=other.x) return x<other.x;
        return y<other.y;
    }
}p[N+5];
int j,mn=INT_MAX;
vector<pair<double,int>>v;
long long distsq(int i,int j) {
    return (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
}
double calc(int i,int j,int k) {
    if (j==k) return 0;
    long long a2=distsq(i,j),b2=distsq(j,k),c2=distsq(i,k);
    double a=sqrt(a2),b=sqrt(b2),c=sqrt(c2);
    double temp=acos((a2+b2-c2)/(2*a*b));
    temp=temp*180/3.14;
    return temp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("DIVPOINT.INP","r",stdin);
    freopen("DIVPOINT.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].x>>p[i].y;
    }
    sort(p+1,p+1+n);
    for (int i=2;i<=n;i++) {
        if (p[i].y<mn) {
            mn=p[i].y;
            j=i;
        }
    }
    for (int i=2;i<=n;i++) v.push_back({calc(1,j,i),i});
    sort(v.begin(),v.end());
    int id;
    if (v.size()%2==0) id=v[v.size()/2-1].second;
    else id=v[v.size()/2].second;
    cout<<p[j].x<<' '<<p[j].y<<' '<<p[id].x<<' '<<p[id].y;
}
