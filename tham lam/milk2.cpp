#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,res=0;
    cin>>n>>m;
    pair<int,int>p[m];
    for (int i=0;i<m;i++) cin>>p[i].first>>p[i].second;
    sort(p,p+m);
    for (int i=0;i<m;i++) {
        if(p[i].second>=n) {
            res+=n*p[i].first;
            break;
        } else {
            res+=p[i].second*p[i].first;
            n-=p[i].second;
        }
        //cout<<n<<' '<<res<<endl;
    }
    cout<<res;
}
