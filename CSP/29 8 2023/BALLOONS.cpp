#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
double x[N+5],r[N+5];
stack<pair<double,double>>st;
double calc(double X,double R) {
    while (!st.empty()) {
        double x1=st.top().first;
        double r1=st.top().second;
        R=min(R,(x1-X)*(x1-X)/(4*r1));
        if (R>=r1) st.pop();
        else break;
    }
    st.push({X,R});
    return R;
}
int main() {
    freopen("BALLOONS.INP","r",stdin);
    freopen("BALLOONS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>r[i];
    st.push({x[1],r[1]});
    cout<<setprecision(3)<<fixed<<r[1]<<'\n';
    for (int i=2;i<=n;i++) {
        cout<<setprecision(3)<<fixed<<calc(x[i],r[i])<<'\n';
    }
}
