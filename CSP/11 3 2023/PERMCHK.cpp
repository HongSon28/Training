#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,cnt=0;
        cin>>n;
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
        sort(b.begin(),b.end());
        for (int i=0;i<n;i++) {
            if (a[i]==b[i])
                cnt++;
        }
        if (cnt==n) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}
