#include<bits/stdc++.h>
using namespace std;
const int N=17000;
int t;
int n,k;
multiset<int>s;
int a[N+5];
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=k;i++) s.insert(a[i]);
        for (int i=1;i<=n-k+1;i++) {
            cout<<*s.begin()<<' ';
            auto it=s.lower_bound(a[i]);
            s.erase(it);
            s.insert(a[i+k]);
        }
        s.clear();
        cout<<endl;
    }
}
