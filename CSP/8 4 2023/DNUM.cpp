#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool p[N+2];
vector<int>v;
void sang() {
    fill(p,p+N+2,true);
    p[0]=false;
    p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    sang();
    freopen("DNUM.INP","r",stdin);
    freopen("DNUM.OUT","w",stdout);
    int n;
    cin>>n;;
    while (n--) {
        map<int,int>mp;
        int a,b;
        cin>>a>>b;
        for (int i=0;i<v.size();i++) {
            while (a%v[i]==0) {
                mp[v[i]]++;
                a/=v[i];
            }
        }
        if (a!=1) mp[a]++;
        for (int i=0;i<v.size();i++) {
            while (b%v[i]==0) {
                mp[v[i]]--;
                b/=v[i];
            }
        }
        if (b!=1) mp[b]--;
        int res=0;
        for (auto i=mp.begin();i!=mp.end();i++) res+=abs(i->second);
        cout<<res<<endl;
    }
}
