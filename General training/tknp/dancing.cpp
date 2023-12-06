#include<bits/stdc++.h>
using namespace std;
int n;
int res=0;
int a[100001];
int b[100001];
multiset<int>sa,sb;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        if (b[i]>=0) sa.insert(b[i]);
        else sb.insert(abs(b[i]));
    }
    for (int i=1;i<=n;i++) {
        if (a[i]>=0) {
            auto it=sb.upper_bound(a[i]);
            if (it!=sb.end()&&!sb.empty()) {
                res++;
                sb.erase(it);
            }
        } else {
            auto it=sa.lower_bound(abs(a[i]));
            if (it!=sa.begin()&&!sa.empty()) {
                it--;
                sa.erase(it);
                res++;
            }
        }
    }
    cout<<res;
}
