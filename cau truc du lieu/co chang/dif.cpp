#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int t;
    cin>>t;
    set<int>s;
    s.insert(t);
    cout<<0<<endl;
    int mx=0;
    for (int i=1;i<n;i++) {
        cin>>t;
        s.insert(t);
        auto it=s.find(t);
        if (it==s.begin()) {
            auto it1=it;
            it1++;
            if (*it1-*it>mx) {
                mx=*it1-*it;
            }
        } else if (it==s.end()){
            auto it2=it;
            it2--;
            if (*it-*it2>mx) {
                mx=*it-*it2;
            }
        } else {
           auto it1=it, it2=it;
           it1++;
           it2--;
           if (*it1-*it2==mx) {
                mx=max(*it1-*it,*it-*it2);
           } else {
                mx=max(*it1-*it,mx);
                mx=max(*it-*it2,mx);
           }
        }
        cout<<mx<<endl;
    }
}
