#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("DNUM.INP","r",stdin);
    freopen("DNUM.OUT","w",stdout);
    int n;
    cin>>n;;
    while (n--) {
        map<int,int>mp;
        int a,b;
        cin>>a>>b;
        for (int i=2;i*i<=a;i++) {
            while (a%i==0) {
                mp[i]++;
                a/=i;
            }
        }
        if (a!=1) mp[a]++;
        for (int i=2;i*i<=b;i++) {
            while (b%i==0) {
                mp[i]--;
                b/=i;
            }
        }
        if (b!=1) mp[b]--;
        int res=0;
        for (auto i=mp.begin();i!=mp.end();i++) res+=abs(i->second);
        cout<<res<<endl;
    }
}
