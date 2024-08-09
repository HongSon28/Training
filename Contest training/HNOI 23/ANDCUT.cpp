#include<bits/stdc++.h>
using namespace std;
long long m,n,q;
vector<int>v;
long long cnt(int j,int tt) {
    if (tt==-1) return 1;
    int k=v[tt];
    int dak=j/(2*k);
    int res=dak*cnt(k,tt-1);
    if (j%(2*k)!=0) res+=cnt(min(k,j%(2*k)),tt-1);
    return res;
}
long long cal(long long x, long long dak) {
    v.clear();
    for (int i=0;i<=30;i++) {
        if ((dak>>i)&1) v.push_back((1<<i));
    }
    return cnt(x+1,v.size()-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>q;
    while (q--) {
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        cout<<cal(ry,lx)-cal(ly,lx)+cal(rx,ly)-cal(lx,ly)+((lx&ly)==0)<<'\n';
    }
}
