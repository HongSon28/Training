#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,k;
bool flag;
pair<int,int>a[N+5];
int main() {
    cin>>t;
    while (t--) {
        flag=true;
        cin>>n>>k;
        for (int i=1;i<=n;i++) {
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a+1,a+1+n);
        for (int i=1;i<=n;i++) {
            if (a[i].second!=i) {
                if ((a[i].second+i)%k!=0) flag=false;
            }
        }
        if (!flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
