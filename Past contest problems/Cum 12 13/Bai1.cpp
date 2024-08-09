#include<bits/stdc++.h>
using namespace std;
struct ps {
    int ts,ms;
    float val;
};
bool comp (ps a, ps b) {
    return a.val<b.val;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<ps>v;
    ps a1,a2;
    a1.ts=0, a1.ms=1, a1.val=0;
    a2.ts=1, a2.ms=1, a2.val=1;
    v.push_back(a1);
    v.push_back(a2);
    for (int i=2;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (__gcd(i,j)==1) {
                ps t;
                t.ts=j;
                t.ms=i;
                t.val=(float)j/(float)i;
                v.push_back(t);
            }
        }
    }
    sort (v.begin(),v.end(),comp);
    cout<<v.size()<<endl;
    if (k<=v.size()) {
        cout<<v[k-1].ts<<' '<<v[k-1].ms;
    } else {
        cout<<"-1";
    }
}
