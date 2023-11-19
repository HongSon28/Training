#include<bits/stdc++.h>
using namespace std;
int n;
double m;
double a[16];
int sign[16];
double res=-1e9;
void check() {
    stack<double>st;
    st.push(a[1]);
    for (int i=2;i<=n;i++) {
        if (sign[i-1]==1) st.push(a[i]);
        else if (sign[i-1]==2) st.push(-a[i]);
        else if (sign[i-1]==3) {
            double temp=st.top();
            st.pop();
            st.push(temp*a[i]);
        } else {
            double temp=st.top();
            st.pop();
            st.push(temp/a[i]);
        }
    }
    double sum=0;
    while (!st.empty()) {
        sum+=st.top();
        st.pop();
    }
    if (sum<=m) res=max(res,sum);
}
void rec(int k) {
    if (k==n) {
        check();
        return;
    }
    for (int i=1;i<=4;i++) {
        sign[k]=i;
        rec(k+1);
    }
}
int main() {
    freopen("DIENPT.INP","r",stdin);
    freopen("DIENPT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    rec(1);
    cout.precision(3);
    cout<<fixed<<res;
}
