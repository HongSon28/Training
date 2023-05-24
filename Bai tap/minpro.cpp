#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll ma=max(x,a-n),mb=max(y,b-n);
        //cout<<ma<<' '<<mb<<' ';
        if (ma<=mb) {
            ll l=n-(a-ma);
            mb=max(y,b-l);
            cout<<ma*mb<<endl;
        } else {
            ll l=n-(b-mb);
            ma=max(x,a-l);
            cout<<ma*mb<<endl;
        }
    }
}
