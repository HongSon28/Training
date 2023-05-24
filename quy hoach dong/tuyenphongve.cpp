#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int n,res=0;
        cin>>n;
        int a[n]={};
        for (int i=0;i<n;i++) cin>>a[i];
        vector<int>f(n+1),b(n+1,INT_MAX);
        b[0]=INT_MIN;
        for (int i=0;i<n;i++) {
            int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            b[k]=a[i];
            res=max(res,k);
        }
        cout<<res<<endl;
    }
}
