#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        bool flag=false;
        int n;
        cin>>n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) {
            int j=a[i];
            int k=a[j];
            if (a[k]==i&&!flag) {
                flag=true;
            }
        }
        if (!flag)
            cout<<"</3"<<endl;
        else
            cout<<"<3"<<endl;
    }
}
