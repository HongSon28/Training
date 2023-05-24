#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
bool p[N+1];
vector <int> v;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2; i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int dem(int x,int y) {
    int res=0,cur=y;
    while (cur<=x) {
        res+=x/cur;
        cur*=y;
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        map<int,int>mp;
        int n,m;
        cin>>n>>m;
        for (int i=0;i<v.size();i++) {
            while (m%v[i]==0) {
                m/=v[i];
                mp[v[i]]++;
            }
        }
        if (m!=1) mp[m]++;
        int res=INT_MAX;
        for (int i=0;i<v.size();i++) {
            res=min(res,dem(n,v[i])/mp[v[i]]);
        }
        cout<<res;
    }
}
