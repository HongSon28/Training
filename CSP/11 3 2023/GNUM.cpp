#include<bits/stdc++.h>
using namespace std;
vector<long long>n(7);
int main() {
    //freopen("GNUM.INP","r",stdin);
    //freopen("GNUM.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        int flag=0;
        for (int i=0;i<7;i++) cin>>n[i];
        sort(n.begin(),n.end());
        int a=n[0],b=n[1],c=n[6]-a-b;
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
}
