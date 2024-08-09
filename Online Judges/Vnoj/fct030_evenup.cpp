#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,t;
stack<int>s;
int res;
int main() {
    cin>>n;
    res=n;
    while (n--) {
        cin>>t;
        t%=2;
        if (!s.empty()&&t==s.top()) {
            s.pop();
            res-=2;
        } else s.push(t);
    }
    cout<<res;
}
