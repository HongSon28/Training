#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d,r;
    while (cin>>n>>d>>r) {
        int res=0;
        if (n==0&&d==0&&r==0) break;
        vector<int>a,b;
        for (int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        for (int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            b.push_back(temp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        for (int i=0;i<a.size();i++) {
            if (a[i]+b[i]>d) res+=(a[i]+b[i]-d)*r;
        }
        cout<<res<<endl;
    }
}
