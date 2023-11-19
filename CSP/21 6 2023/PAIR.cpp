#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
stack<int>st;
map<int,int>cnt;
int n;
int a[N+5];
int res;
int main() {
    freopen("PAIR.INP","r",stdin);
    freopen("PAIR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while(!st.empty()&&a[i]>a[st.top()]) {
            cnt[a[st.top()]]--;
            st.pop();
            res++;
        }
        if (!st.empty()) {
            if (a[i]==a[st.top()]) res+=cnt[a[st.top()]]+(st.size()>cnt[a[i]]);
            else res++;
        }
        st.push(i);
        cnt[a[i]]++;
    }
    cout<<res;
}
