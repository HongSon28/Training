#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int a[n+1];
        vector<int>res;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<n;i++) {
            for (int j=i+1;j<=n;j++) {
                res.push_back(__gcd(a[i],a[j]));
            }
        }
        sort(res.begin(),res.end(),greater<int>());
        cout<<res[1]<<endl;
    }
}
