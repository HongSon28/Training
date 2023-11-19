#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int res;
queue<int>q;
stack<int>st;
int main() {
    freopen("TRAFFIC.INP","r",stdin);
    freopen("TRAFFIC.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        q.push(i);
    }
    for (int i=1;i<=n;i++) {
        while ((q.front()!=a[i])&&(st.empty()||st.top()!=a[i])) {
            if (!q.empty()) {
                res++;
                st.push(q.front());
                q.pop();
            } else break;
        }
        if (!q.empty()&&q.front()==a[i]) {
            res++;
            q.pop();
        } else if (!st.empty()&&st.top()==a[i]) {
            res++;
            st.pop();
        } else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl<<res;
}
