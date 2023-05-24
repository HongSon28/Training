#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5;
pair<int,int> a[N+5];
vector<int>f,s;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
        f.push_back(a[i].first);
        s.push_back(a[i].second);
    }
    sort(f.begin(),f.end(),greater<int>());
    sort(s.begin(),s.end());
    if (s[0]<f[0]) {
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++) {
            if (a[i].first==f[0]) {
                cout<<i<<' ';
                break;
            }
        }
        for (int i=1;i<=n;i++) {
            if (a[i].second==s[0]) {
                cout<<i;
                break;
            }
        }
    } else cout<<"NO";
}
