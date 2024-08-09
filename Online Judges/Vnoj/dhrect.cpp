#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5;
int k,n;
ll d[N+5];
int main() {
    cin>>k;
    while (k--) {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>d[i];
        sort(d+1,d+1+n,greater<int>());
        int i=1;
        ll res=1,cnt=0;
        while (i<=n) {
            if (d[i]==d[i+1]) {
                cnt++;
                res*=d[i];
                if (cnt==2) break;
                i++;
            }
            i++;
        }
        if (cnt<2) cout<<-1<<endl;
        else cout<<res<<endl;
    }
}
