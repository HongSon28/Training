#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<pair<int,int>> s1;
    set<int> s2;
    int a[n];
    for (int i=1;i<=n;i++) {
        pair<int,int> t;
        cin>>t.first;
        a[i]=t.first;
        t.second=i;
        s1.insert(t);
        s2.insert(i);
    }
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        pair<int,int> p(t,0);
        auto it=s1.lower_bound(p);
        if (it!=s1.end()) {
            int temp=(*it).second;
            cout<<temp<<' ';
            s2.erase(s2.find(temp));
            s1.erase(it);
        } else {
            int temp=*s2.begin();
            cout<<temp<<' ';
            s2.erase(s2.begin());
            s1.erase(make_pair(a[temp],temp));
        }
    }
}
