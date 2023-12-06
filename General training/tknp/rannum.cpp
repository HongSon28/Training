#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
set<int>st;
bool check(int m) {
    map<int,int>m1,m2;
    for (int i=0;i<n;i++) {
        if (m1.count(a[i])==0) {
            m1[a[i]]=i;
            m2[a[i]]=i+1;
        } else {
            m2[a[i]]=max(m2[a[i]],i-m1[a[i]]);
            m1[a[i]]=i;
        }
    }
    for (auto i:st) {
        m2[i]=max(m2[i],n-m1[i]);
    }
    for (auto i=m2.begin();i!=m2.end();i++) {
        //cout<<i->first<<' '<<i->second<<endl;
        if (i->second<=m) return true;

    }
    return false;
}
int main() {
    freopen("RANNUM.INP","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    int lo=1,hi=n;
    while (hi-lo>0) {
        int mid=lo+(hi-lo)/2;
        //cout<<lo<<' '<<hi<<' '<<mid<<' '<<check(mid)<<endl;
        if (check(mid)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}

