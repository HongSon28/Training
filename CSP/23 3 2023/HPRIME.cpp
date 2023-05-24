#include<bits/stdc++.h>
using namespace std;
int h;
vector<int>v,res;
void sang(int n) {
    bool p[n+1];
    memset(p,true,sizeof(p));
    for (int i=2;i<=n;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=n;j+=i) p[j]=false;
        }
    }
}
bool check (int m) {
    int sum=0;
    while (m>0) {
        sum+=m%10;
        m/=10;
    }
    if (sum==h) return true;
    return false;
}
int main() {
    freopen("HPRIME.INP","r",stdin);
    freopen("HPRIME.OUT","w",stdout);
    int n;
    cin>>n>>h;
    sang(n);
    for (int i=0;i<v.size();i++) {
        if (check(v[i])==true) res.push_back(v[i]);
    }
    cout<<res.size()<<endl;
    for (int i=0;i<res.size();i++) cout<<res[i]<<endl;
}
